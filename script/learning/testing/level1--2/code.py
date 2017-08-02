'''
level1 - (ii)
'''
import requests
import json
import re

count = 0
limit = 50
url = 'https://en.wiktionary.org/w/api.php?action=query&titles=%s&prop=revisions&rvprop=content&format=json'
lst = []
with open('../lxml/title.txt', 'r') as f:
	for i in f.read().split('\n'):
		lst.append(i)
		count += 1
		if count == limit:
			break
			pass
		pass
	pass

titles =  '|'.join(lst)

url = url%titles

x = requests.get(url).text
x = json.loads(x)
x = x['query']['pages']

for i in x:
	print x[i]['title'].encode('utf-8')+" : ",
	content = x[i]['revisions'][0]['*']
	content = content.encode('utf-8')
	ipa_list = re.findall("{{IPA[^}]+}}",content)
	print ipa_list