n = int(raw_input())
d = {'Tetrahedron': 4,
	'Cube' : 6,
	'Octahedron' :  8,
	'Dodecahedron' : 12,
	'Icosahedron' : 20
	}

z = 0
while(n>0):
	x = raw_input()
	z += d[x]
	n -=1
	pass

print z