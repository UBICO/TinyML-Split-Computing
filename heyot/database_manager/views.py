from django.http import JsonResponse
from django.core.management import call_command
import pandas as pd
import os
from django.http import HttpResponse
import csv


def export_data_to_csv(request):
   # Call your management command using call_command
    output_file_path = "exported_tests_csv"
    command = 'export_csv'
    call_command(command, output_file_path)

    # Construct the path to the CSV file
    csv_file_path = os.path.join(output_file_path, "TestData.csv")

    # Check if the file exists
    if not os.path.exists(csv_file_path):
        # Handle the case where the file doesn't exist
        return HttpResponse("CSV file not found", status=404)

    # Read the data from the uploaded CSV file
    data = []
    with open(csv_file_path, 'r', newline='') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        for row in csv_reader:
            data.append(row)

    # Create a CSV response with data and header
    response = HttpResponse(content_type='text/csv')
    response['Content-Disposition'] = 'attachment; filename="TestData.csv"'

    if data:
        # Use the keys of the first row as the CSV header
        fieldnames = data[0].keys()
        writer = csv.DictWriter(response, fieldnames=fieldnames)
        writer.writeheader()

        for row in data:
            writer.writerow(row)

    return response