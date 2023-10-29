from django.urls import path
from database_manager.views import export_data_to_csv, export_preprocessed_full_data_csv

urlpatterns = [
    path('api/export_data_to_csv/', export_data_to_csv, name='export_data_to_csv'),
    path('api/export-preprocessed-full-data-to-csv/', export_preprocessed_full_data_csv, name='export_preprocessed_full_data_csv'),

]
