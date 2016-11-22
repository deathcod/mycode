import requests
import json
import csv
import re

s=requests.get("https://www.valueresearchonline.com/funds/fundSelector/default.asp?amc=8799exc=fmp%2Csusp%2Cclose").text
x=re.findall(r'<a class="fundName" id="fundName[\d]+" href="([^"]*?)"[\s\w<>=\"-:?@.;]*?</span>',s)
for k in x:
	print 'https://www.valueresearchonline.com'+k
print "\n"