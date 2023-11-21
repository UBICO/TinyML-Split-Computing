#!/bin/sh

###################################################################################################################################################################################################
# Django Web App Initialization 
###################################################################################################################################################################################################
python manage.py makemigrations database_manager --no-input 
python manage.py migrate database_manager --no-input 
python manage.py makemigrations  --no-input 
python manage.py migrate  --no-input 
python manage.py collectstatic --no-input --clear 
python manage.py shell -c "from django.contrib.auth.models import User; User.objects.filter(username='$DJANGO_USR_PWD').exists() or User.objects.create_superuser('$DJANGO_USR_PWD', '$DJANGO_USR_PWD', '$DJANGO_USR_PWD')"
###################################################################################################################################################################################################
# Django Web App User 
###################################################################################################################################################################################################
python manage.py export_csv ./exported_tests_csv


exec "$@"

