from django.conf.urls import patterns, include, url
from . import views

app_name = 'user_info'

urlpatterns = patterns('',

    url(r'^$',views.index , name='index'),

    # user_info/1/
    url(r'^([0-9]+)/$', views.details, name='details')
)