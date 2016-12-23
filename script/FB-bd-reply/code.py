import requests
import json
import re
from datetime import datetime as dt
'''
This is a python script which performs a specific task to reply to the messages of bday wishes.
'''

__author__ = "Chinmay Rakshit"
__email__  = "chinmay.rakshit@gmail.com"
access_token = 'EAACEdEose0cBAGrbxfgEXglVr8QObIWk138xUU1pgcTNAokcrmD4MqHfZBv4pseGtwNf5xVDb9ZCrFMqqqyJEwR4tZB2MGKl7TiZC3vRCAwSr3T8pJcO54MVexLKNaz3qKchT7TMe6miyO8H84r1g0ghWzzUBwid0ztgiFWQcgZDZD'

def compare_date_(past_time = "2016-12-21T00:01:00+0000", present_time = "2016-12-21T00:01:00+0000"):

	past_time = dt.strptime(past_time, "%Y-%m-%dT%H:%M:%S+0000")
	present_time = dt.strptime(present_time, "%Y-%m-%dT%H:%M:%S+0000")
	
	return True if (present_time - past_time).total_seconds() > 0 else False

def test_message_(message,name):
	if re.findall(r'(?i)h[\w ]*?b[\w ]*?d',message):
		return "Thanks %s :),take care" % name
	else:
		return "Hi, I am a script created by Chinmay,Sorry :( I am unable to understand your message, Chinmay will text you soon\n\n:)\ntake care"

def post_ids():
	
	posts = set()
	with open('code.txt','r') as f:
		for i in f.read().split('\n'):
			posts.add(i[-15:])

	return posts

def reply(posts):

	global access_token
	url = 'https://graph.facebook.com/v2.8/141642176268900_%s?fields=from,created_time,message&access_token='+access_token
	for id_ in posts:
		
		post = json.loads(requests.get(url % id_).text)

		if not "message" in post:
			continue

		name = post["from"]["name"]
		print post["id"]
		print(post["message"])
		message = test_message_(post["message"],name)
		print message
		u = 'https://graph.facebook.com/v2.8/141642176268900_'+id_+'/comments'
		data = {
			"format" : 'json',
			"message" : message,
			"access_token":access_token,
		}
		#print u
		requests.post(u, data=data)
		#print data
		print name+" : success"

if __name__ == '__main__':
	#print compare_date_()
	#print test_message_("Many Many Happy Return Of The Day ......Sontu ..Happy Birth Day To You")
	reply(post_ids())