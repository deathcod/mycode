x,y = raw_input().split()
x = int(x)
y = int(y)
c =0 
while True:

	x = x * 3
	y = y * 2
	c+=1
	if(x > y):
		break
	pass
print c