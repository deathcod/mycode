path = [[0,0,0,0,0],
       [0,1,2,3,0],
       [0,8,0,4,0],
       [0,7,6,5,0],
       [0,0,0,0,0]
      ]


dict = {}
for i in range(0,5):
	for j in range(0,5):
		if path[i][j]!=0:
			dict[path[i][j]] = (i,j)
			pass

l_value = []
for i,value in dict.iteritems():
	l_value.append(value)

print l_value