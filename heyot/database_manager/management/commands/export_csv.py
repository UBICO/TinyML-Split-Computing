from django.core.management.base import BaseCommand
from django.apps import apps
import csv

class Command(BaseCommand):
    help = 'Export data from all models in the app to CSV files'

    def add_arguments(self, parser):
        parser.add_argument('output_dir', type=str, help='Directory where CSV files will be saved')

    def handle(self, *args, **options):
        output_dir = options['output_dir']

        for model in apps.get_models():
            if model.__name__ == "TestData":
                model_name = model.__name__
                csv_file_path = f'{output_dir}/{model_name}.csv'

                # Fetch data from the database table
                data = model.objects.all()

                # Write data to a CSV file
                with open(csv_file_path, 'w', newline='') as csv_file:
                    writer = csv.writer(csv_file)
                    writer.writerow([field.name for field in model._meta.fields])  
                    for item in data:
                        writer.writerow([getattr(item, field.name) for field in model._meta.fields])

                self.stdout.write(self.style.SUCCESS(f"Data from model '{model_name}' exported to '{csv_file_path}'"))
