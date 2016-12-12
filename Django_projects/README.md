to start with the installation 


* virtualenv -p /usr/bin/python3 py3env  
* source py3env/bin/activate  
* pip install django==1.7

create a project

* django-admin startproject basic_project

now change the database to mysql

```
DATABASES = {
'default': {
    'ENGINE': 'django.db.backends.mysql',
    'NAME': 'DB_NAME',
    'HOST': '127.0.0.1',
    'PORT': '3306',
    'USER': 'root',
    'PASSWORD': '',
}}
```

now install the dependencies.

* sudo apt-get install libmysqlclient-dev
* pip install mysqlclient


Now synchronize the db with django

* cd project_name
* project_name$ python manage.py syncdb

level-1 done!!

________________________________________________________________________________________________

#How to add your app to the main project.. 


```python
from django.apps import AppConfig

class User_infoConfig(AppConfig):
	name = 'name of the app'
```

put this in apps.py in the app package.

add a line   
	'user_info.apps.User_infoConfig'

in the "INSTALLED_APPS" section.

So this way you can add your apps.

_________________________________________________________________________________________________ 


#How to add the database file.

	python manage.py makemigrations user_info
	Migrations for 'user_info':
	  0001_initial.py:
	    - Create model info


to see the create table value.

	 python manage.py sqlmigrate user_info 0001

_________________________________________________________________________________________________
