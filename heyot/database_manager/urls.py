from django.urls import path
from database_manager.views import export_data_to_csv

urlpatterns = [
    path('api/export_data_to_csv/', export_data_to_csv, name='export_data_to_csv'),
]
