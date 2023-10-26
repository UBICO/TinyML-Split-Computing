from django.shortcuts import render
from .MQTTClientManager import MQTTClientManager # Change the import path to the correct one for the class
import threading

mqtt_manager = MQTTClientManager()
mqtt_client_thread = None

def start_mqtt_client(request):
    global mqtt_client_thread
    if mqtt_client_thread is None or not mqtt_client_thread.is_alive():
        mqtt_client_thread = threading.Thread(target=mqtt_manager.run_mqtt_client)
        mqtt_client_thread.start()
        notification = "MQTT Client started."
    else:
        notification = "MQTT Client is already running."
    return render(request, 'heyot/mqtt_client_menager/mqtt_client.html', {'notification': notification})

def stop_mqtt_client(request):
    global mqtt_client_thread
    if mqtt_client_thread and mqtt_manager.mqtt_client_running:
        mqtt_manager.disconnect_mqtt_client()
        mqtt_client_thread.join()  # Ensure the thread finishes before proceeding.
        mqtt_client_thread = None  # Resetting the thread
        notification = "MQTT Client stopped."
    else:
        notification = "MQTT Client is not running."
    return render(request, 'heyot/mqtt_client_menager/mqtt_client.html', {'notification': notification})
