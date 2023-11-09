from django.shortcuts import render
from .MQTTClientManager import MQTTClientManager # Change the import path to the correct one for the class
import threading
from django.http import JsonResponse


mqtt_manager = MQTTClientManager()
mqtt_client_thread = None


def get_mqtt_info(request):
    connected_devices_data = mqtt_manager.get_connected_devices_and_message_count()
    data = {'devices': connected_devices_data}
    return JsonResponse(data)

def start_mqtt_client(request):
    global mqtt_client_thread
    if mqtt_client_thread is None or not mqtt_client_thread.is_alive():
        mqtt_client_thread = threading.Thread(target=mqtt_manager.run_mqtt_client)
        mqtt_client_thread.start()
        notification = "MQTT Client started."
    else:
        notification = "MQTT Client is already running."

    # Get connected device count and total message count
    connected_devices_data = mqtt_manager.get_connected_devices_and_message_count()

    return render(request, 'heyot/mqtt_client_menager/mqtt_client.html', {
        'notification': notification,
        'devices': connected_devices_data
    })


def stop_mqtt_client(request):
    global mqtt_client_thread
    if mqtt_client_thread and mqtt_manager.mqtt_client_running:
        mqtt_manager.disconnect_mqtt_client()
        mqtt_client_thread.join()  # Ensure the thread finishes before proceeding.
        mqtt_client_thread = None  # Resetting the thread
        notification = "MQTT Client stopped."
    else:
        notification = "MQTT Client is not running."

    # Get connected device count and total message count
    connected_devices_data = mqtt_manager.get_connected_devices_and_message_count()

    return render(request, 'heyot/mqtt_client_menager/mqtt_client.html', {
        'notification': notification,
        'devices': connected_devices_data
    })