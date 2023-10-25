###################################################################################################################################################################################################
# Configuration 
###################################################################################################################################################################################################
$DevelopmentUser = Read-Host -Prompt 'Input the [Development User Name]'
###################################################################################################################################################################################################
# Containers initialization
###################################################################################################################################################################################################
docker-compose -f ..\docker-compose.dev.yml up -d --build
###################################################################################################################################################################################################
# Django Web App Initialization 
###################################################################################################################################################################################################
docker exec -it iot python manage.py makemigrations mqtt_client --no-input 
docker exec -it iot python manage.py migrate mqtt_client --no-input 
docker exec -it iot python manage.py collectstatic --no-input --clear 
docker exec -it iot python manage.py shell -c "from django.contrib.auth.models import User; User.objects.filter(username='$DevelopmentUser').exists() or User.objects.create_superuser('$DevelopmentUser', '$DevelopmentUser', '$DevelopmentUser')"
###################################################################################################################################################################################################
# Django Web App User 
###################################################################################################################################################################################################
docker exec -it iot python manage.py export_csv ./exported_tests_csv