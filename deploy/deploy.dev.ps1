###################################################################################################################################################################################################
# Configuration 
###################################################################################################################################################################################################
$DevelopmentUser = Read-Host -Prompt 'Input the [Development User Name]'
###################################################################################################################################################################################################
# Containers initialization
###################################################################################################################################################################################################
docker-compose -f ..\docker-compose.dev.yml --env-file ..\environment\.env.dev up -d --build
###################################################################################################################################################################################################
# Django Web App Initialization 
###################################################################################################################################################################################################
docker exec -it heyot_web python manage.py makemigrations database_manager --no-input 
docker exec -it heyot_web python manage.py migrate database_manager --no-input 
docker exec -it heyot_web python manage.py makemigrations  --no-input 
docker exec -it heyot_web python manage.py migrate  --no-input 
docker exec -it heyot_web python manage.py collectstatic --no-input --clear 
docker exec -it heyot_web python manage.py shell -c "from django.contrib.auth.models import User; User.objects.filter(username='$DevelopmentUser').exists() or User.objects.create_superuser('$DevelopmentUser', '$DevelopmentUser', '$DevelopmentUser')"
###################################################################################################################################################################################################
# Django Web App User 
###################################################################################################################################################################################################
docker exec -it heyot_web python manage.py export_csv ./exported_tests_csv