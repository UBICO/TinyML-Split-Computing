from django.http import JsonResponse
from django.core.management import call_command
import pandas as pd
import os
from django.http import HttpResponse
import csv
import numpy as np
import ast


def export_preprocessed_full_data_csv(request):
    # Call your management command using call_command
    output_file_path = "exported_tests_csv"
    command = 'export_csv'
    call_command(command, output_file_path)

    # Construct the path to the CSV file
    csv_file_path = os.path.join(output_file_path, "TestData.csv")
    full_data_csv_file_path = os.path.join(output_file_path, "PreprocessedFullData.csv")


    # Check if the file exists
    if not os.path.exists(csv_file_path):
        # Handle the case where the file doesn't exist
        return HttpResponse("CSV file not found", status=404)

    # Read the data from the uploaded CSV file
    df = pd.read_csv(csv_file_path)
    

    # Convert string representations of lists to actual lists
    df["inference_dev"] = df["inference_dev"].apply(lambda x: ast.literal_eval(x))
    df["inference_edge"] = df["inference_edge"].apply(lambda x: ast.literal_eval(x))

    # Expand the lists into separate columns
    df = pd.concat([df, pd.DataFrame(df['inference_dev'].tolist()).add_suffix('_inference_dev')], axis=1)
    df = pd.concat([df, pd.DataFrame(df['inference_edge'].tolist()).add_suffix('_inference_edge')], axis=1)

    # Remove the original "inference_dev" and "inference_edge" columns
    df.drop(["inference_dev", "inference_edge"], axis=1, inplace=True)

    df['chosen_offloading_layer'] = df['chosen_offloading_layer'].astype(int)

    for index, row in df.iterrows():
        chosen_offloading_layer = row['chosen_offloading_layer']
        offloading_inf_cols = []
        for i in range(0,7):
            if i < chosen_offloading_layer:
                offloading_inf_cols.append(f"{i}_inference_dev") 
            else:
                offloading_inf_cols.append(f"{i}_inference_edge")
        
        # Calculate 'total_time_with_offloading' for the current row and update the DataFrame
        df.at[index, 'total_time_with_offloading'] = df.loc[index, offloading_inf_cols].sum()

        inference_dev_cols = [f"{i}_inference_dev" for i in range(0,7)]
        df.at[index, 'total_time_no_offloading_dev'] = df.loc[index, inference_dev_cols].sum()
        
        inference_edge_cols = [f"{i}_inference_edge" for i in range(0,7)]
        df.at[index,'total_time_fast_offloading_edge'] = df.loc[index, inference_edge_cols].sum()

    try:
        df['time_saved'] = df['total_time_no_offloading_dev'] - df['total_time_with_offloading']
    except Exception as e:
        df['time_saved'] = np.nan
    df.to_csv(full_data_csv_file_path, index=False)

    data = []
    with open(full_data_csv_file_path, 'r', newline='') as csv_file:
            csv_reader = csv.DictReader(csv_file)
            for row in csv_reader:
                data.append(row)

    # Create a CSV response with data and header
    response = HttpResponse(content_type='text/csv')
    response['Content-Disposition'] = f'attachment; filename="PreprocessedFullData.csv"'

    if data:
        # Use the keys of the first row as the CSV header
        fieldnames = data[0].keys()
        writer = csv.DictWriter(response, fieldnames=fieldnames)
        writer.writeheader()

        for row in data:
            writer.writerow(row)
    return response

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