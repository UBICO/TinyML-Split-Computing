python manage.py makemigrations
python manage.py migrate
python manage.py collectstatic --no-input
python manage.py shell -c "from django.contrib.auth.models import User; User.objects.filter(username='iot').exists() or User.objects.create_superuser('iot', 'iot@iot.iot', 'iot')"

# Use "$@" to execute the command passed to the script
exec "$@"