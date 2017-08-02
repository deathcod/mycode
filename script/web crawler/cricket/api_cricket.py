from gi.repository import Notify
from time import sleep
import requests
import json
while True:
	data={
		'unique_id' : '951363'
	}
	h=requests.get('http://cricapi.com/api/cricketScore/',data=data)
	result=json.loads(h.text)
	s=result['score']
	#print(s)
	k=s[0:s.find(' ')]+'\n'
	k+=s[s.find(' ')+1:s.find(' ',s.find(' ')+1)]+'\n'
	k+="overs:"+s[s.find('(')+1:s.find(' ',s.find('('))]+'\n'
	k+="batsmans:"+'\n'
	k+="    "+s[s.find(',')+1:s.find(',',s.find(',')+1)]+'\n'
	#k+="    "+s[s.find(',',s.find(',')+1)+1:s.find(',',s.find(',',s.find(',')+1)+1)]
	Notify.init("Test")
	notice = Notify.Notification.new(k)
	notice.show()
	sleep(30)
pass