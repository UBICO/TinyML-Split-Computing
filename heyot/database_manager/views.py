from django.http import JsonResponse
from django.core.management import call_command

def export_data_to_csv(request, output_dir):
    # Call your management command using call_command
    call_command('export_data_to_csv', output_dir)

    return JsonResponse({'message': f'Data export complete - {output_dir}'})
