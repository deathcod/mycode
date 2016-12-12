from django.shortcuts import render, get_object_or_404
from .models import info

# Create your views here.

def index(request):
	
	info_list = info.objects.all()
	context = {'info_list' : info_list}
	return render(request, 'user_list/index.html', context)	

def details(request, album_id):

	user = get_object_or_404(info, id = album_id)
	return render(request, 'user_list/details.html', {'user' : user})	