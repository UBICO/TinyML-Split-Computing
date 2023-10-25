from django.urls import path
from .views import start_mqtt_client, stop_mqtt_client

urlpatterns = [
    path('mqtt-client/start/', start_mqtt_client, name='start_mqtt_client'),
    path('mqtt-client/stop/', stop_mqtt_client, name='stop_mqtt_client'),
]
