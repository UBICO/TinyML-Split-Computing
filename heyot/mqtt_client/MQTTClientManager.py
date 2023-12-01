import paho.mqtt.client as mqtt
import time
import json
import ntplib
import pandas as pd
import random
import sys
import numpy as np
from neural_networks.NNManager import NNManager
from database_manager.DBManager import DBManager
from offload_monitor.OffloadingManager import OffloadingManager

import logging
logger = logging.getLogger(__name__)

class MQTTClientManager:
    def __init__(self):
        # Initialize the dictionary to track connected devices and last message time
        self.connected_devices = {}

        # Mqtt Broker Info 
        self.mqtt_client        = None
        self.MQTT_BROKER        = 'FLOWFACTORY-FABIO'   # Broker Hostname, resolves even without .local when using hotspot
        self.MQTT_PORT          = 1883                  # MQTT broker port
        self.MQTT_QOS           = 2                     # MQTT QOS Level

        self.subscribe_topics   = [
            'comunication/device/nn_offloading',
            'comunication/device/nn_analytics',
        ]

        self.publish_topic      = [
            'comunication/edge/nn_offloading',     
            'comunication/edge/nn_analytics',             
            'comunication/nn_prediction',
        ]
        
        # Timer Syncronization
        self.NTP_SERVER         = "0.it.pool.ntp.org"   # NTP Server Name, should be the same used on the esp32 board
        self.start_time         = None
        self.time_offset        = None

        self.db_manager         = DBManager()
        self.offloading_manager = None
        self.nn_manager         = None 

        self.nn_info_dict       = {} # Dictionary to store information for different neural networks
        self.nn_analytics_path  = None

    def on_connect(self, client, userdata, flags, rc):
        logger.info(f"MQTT Cli Connected: {rc}")
        for topic in self.subscribe_topics:
            client.subscribe(topic)

    def get_message_data(self, msg):
        logger.info(f"Reading Message Data")
        try:
            payload = msg.payload
            payload_size_bits = sys.getsizeof(payload)*8
            return json.loads(msg.payload.decode('utf-8')), payload_size_bits
        except json.JSONDecodeError:
            logger.info("Error: Payload is not a valid JSON.")
            return None, None

    def on_message(self, client, userdata, msg):
        # Get message data if the message is from an old communication it gets discarded
        message_data, payload_size_bits = self.get_message_data(msg)
        if message_data is None or float(message_data.get('timestamp', None)) < self.start_time:
            return

        # Get the Neural Network id
        nn_id = message_data.get('nn_id', None)

        # Update the connected devices dictionary with the latest message timestamp
        device_id = nn_id
        if device_id:
            if device_id not in self.connected_devices:
                self.connected_devices[device_id] = {
                    'last_message_time': time.time(),
                    'total_message_count': 1
                }
            else:
                self.connected_devices[device_id]['last_message_time'] = time.time()
                self.connected_devices[device_id]['total_message_count'] += 1

        # Store Test Information   
        logger.info(f"##################################################################################################################")
        logger.info(f"Message for: {nn_id}")
        logger.info(f"##################################################################################################################")
        self.db_manager.store_test_data(
            message_uiid=message_data.get('messageUIID', None), 
            nn_id=nn_id
        )

        logger.info(f"{message_data}")
        if nn_id is not None:
            self.nn_analytics_path = f'./neural_networks/ai_models/{nn_id}/{nn_id}_analytics.csv'
            analytics_data = pd.read_csv(self.nn_analytics_path)
            msg_latency, avg_speed = self.evaluate_latency_and_speed(message_data, payload_size_bits)

            # Create or get the NNManager instance for the neural network
            nn_manager = self.nn_info_dict.get(nn_id)
            if nn_manager is None:
                nn_manager = NNManager(nn_id=nn_id)
                self.nn_info_dict[nn_id] = nn_manager

            # Handle the message based on the topic
            if msg.topic == "comunication/device/nn_offloading":
                start_layer_index = int(message_data.get('last_computed_layer'))
                logger.info(f"Asked to compute from layer: {start_layer_index}")
                # Predict
                fake_data = np.random.rand(1, 9)
                layer_outputs, model_loading_time, update_time = nn_manager.perform_predict(
                    start_layer_index=start_layer_index, data=fake_data)
                # Publish the prediction of each layer
                self.publish_message(topic='comunication/nn_prediction', message=json.dumps(layer_outputs))
                # Store Test Information
                self.db_manager.store_test_data(
                    message_uiid=message_data.get('messageUIID', None),
                    model_loading_time=model_loading_time,
                    update_time=update_time
                )

            if msg.topic == "comunication/device/nn_analytics":
                # Get Inference Time of the device
                device_analytics = pd.DataFrame(message_data)
                inference_time_device = device_analytics["layer_inference_time"].tolist()
                inference_time_device = [x / 1000 for x in inference_time_device]
                # Get inference time of the edge
                synt_load_edge = 1.7
                inference_time_edge = [x / synt_load_edge for x in inference_time_device]
                # Run offloading algorithm
                self.offloading_manager = OffloadingManager(
                    avg_speed=avg_speed,
                    num_layers=len(device_analytics) - 1,
                    layers_sizes=analytics_data["layer_size"].tolist(),
                    inference_time_edge=inference_time_edge,
                    inference_time_device=inference_time_device
                )
                best_layer, _, offloaded_layer_data_size, layer_zero_data_size = self.offloading_manager.static_offloading_evaluation()
                # Publish Prediction
                self.publish_message(topic='comunication/edge/nn_offloading', message=json.dumps({"layer": best_layer}))
                # Store Test Information
                self.db_manager.store_test_data(
                    message_uiid=message_data.get('messageUIID', None),
                    layer_zero_data_size=layer_zero_data_size,
                    offloaded_layer_data_size=offloaded_layer_data_size,
                    avg_speed=avg_speed, avg_latency=msg_latency,
                    synt_load_edge=synt_load_edge,
                    chosen_offloading_layer=best_layer,
                    inference_dev=inference_time_device,
                    inference_edge=inference_time_edge,
                    algo_id='0.0.0'
                )

    def evaluate_latency_and_speed(self, message_data, payload_size_bits):
        # Calculate Latency in seconds and the average_speed
        current_time = time.time_ns() / 1_000_000_000
        msg_latency = round( abs(current_time - float(message_data.get('timestamp', 0)) - float(self.time_offset)), 5) 
        synt_latency = random.uniform(1, 30)
        avg_speed =  payload_size_bits / (msg_latency*synt_latency)
        # Store Test Information   
        self.db_manager.store_test_data(
            message_uiid=message_data.get('messageUIID', None), 
            synt_latency=synt_latency
        )
        return  msg_latency, avg_speed

    def run_mqtt_client(self):
        self.set_time_from_ntp()
        self.mqtt_client = mqtt.Client(client_id="data_reader", clean_session=True)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client_running = True
        self.mqtt_client.connect(self.MQTT_BROKER, self.MQTT_PORT, keepalive=60)
        self.mqtt_client.loop_forever()

    def disconnect_mqtt_client(self):
        logger.info(f"MQTT Cli Disconnected")
        if self.mqtt_client_running:
            self.mqtt_client_running = False
            self.mqtt_client.unsubscribe('comunication/+')
            self.mqtt_client.disconnect()

    def set_time_from_ntp(self):
        clientNTP = ntplib.NTPClient()
        response = clientNTP.request(self.NTP_SERVER, version=3)
        current_time = response.tx_time
        # Offset between NTP time and system time
        self.time_offset = time.time() - current_time  
        ntp_time = abs(time.time() - ( float(self.time_offset) ))
        self.start_time = ntp_time # Start the timer
        logger.info(f"NTP Time Configured: {ntp_time}")

    def publish_message(self, topic, message):
        if self.mqtt_client is not None:
            try:
                result = self.mqtt_client.publish(topic, message, qos=2)
                if result.rc == mqtt.MQTT_ERR_SUCCESS:
                    logger.info(f"Published message '{message}' to topic '{topic}' with QoS 2")
                else:
                    logger.info(f"Failed to publish message to topic '{topic}'")
            except Exception as e:
                logger.info(f"Error publishing message: {e}")
        else:
            logger.info("MQTT client is not initialized. Call 'run_mqtt_client' first.")

    def get_connected_devices_and_message_count(self):
        # Calculate the current time
        current_time = time.time()

        # Initialize a list to store data for all connected devices
        connected_devices_data = []

        # Iterate through connected devices and count the messages
        for device_id, device_info in self.connected_devices.items():
            last_message_time = device_info['last_message_time']
            total_messages = device_info['total_message_count']

            # Check if the device has sent a message in the last 10 seconds
            if current_time - last_message_time <= 10:
                device_data = {
                    'device_id': device_id,
                    'connected_device_count': 1,  # You can leave it as 1 for each device
                    'total_message_count': total_messages
                }
                connected_devices_data.append(device_data)

        return connected_devices_data