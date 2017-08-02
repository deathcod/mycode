#!/usr/bin/env python
import requests
import re
from time import sleep
from gi.repository import Notify
while True :
	s=requests.get('http://www.cricbuzz.com/live-cricket-scores/15803/wi-vs-ind-2nd-semi-final-icc-world-t20-2016')
	if s.status_code==200 :
		k=s.text
		k=k[k.find('d\">WI')+3:k.find(')',k.find('d\">WI'))+1]
		if k=='':
			break
		Notify.init("Test")
		notice = Notify.Notification.new(k)
		notice.show()
		sleep(500)