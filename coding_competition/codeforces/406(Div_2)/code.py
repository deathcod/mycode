a,b = raw_input().split()
a,b = int(a),int(b)
c,d = raw_input().split()
c,d = int(c),int(d)

ff = b - d
if ff == 0:
	print b
	exit()

for x in range(1000):
	for y in range(1000):
		#print x , y, y * c - x * a,ff
		if y * c - x * a > ff:
			break
		if y * c - x * a == ff:
			print b + x * a
			exit()
		if y * c - x * a < ff:
			continue
		pass
	pass


print -1