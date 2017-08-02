from lxml import html
import requests

page = requests.get('https://en.wiktionary.org/wiki/Index:Albanian')
tree = html.fromstring(page.content)

''' xpath
/html/body/div[3]/div[3]/div[4]/div[1]/ol[1]/li[1]/a
/html/body/div[3]/div[3]/div[4]/div[1]/ol[1]/li[2]/a
/html/body/div[3]/div[3]/div[4]/div[1]/ol[36]/li[1]/span/a     <-- avoid this
'''

title = tree.xpath('/html/body/div[3]/div[3]/div[4]/div[1]/ol/li/a/@title')
href = tree.xpath('/html/body/div[3]/div[3]/div[4]/div[1]/ol/li/a/@href')


f = open('title.txt', 'a')
for i in title:
	i = i.encode('utf-8')
	f.write(i+"\n")
	pass
#print href

f = open('href.txt', 'a')
for i in href:
	i = i.encode('utf-8')
	f.write(i+"\n")
	pass

