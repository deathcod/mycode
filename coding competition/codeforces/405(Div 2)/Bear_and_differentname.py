text = ['Aa', 'Ab', 'Ac', 'Ad', 'Ae', 'Af', 'Ag', 'Ah', 'Ai', 'Aj', 'Ak', 'Al', 'Am', 'An', 'Ao', 'Ap', 'Aq', 'Ar', 'As', 'At', 'Au', 'Av', 'Aw', 'Ax', 'Ay', 'Ba', 'Bb', 'Bc', 'Bd', 'Be', 'Bf', 'Bg', 'Bh', 'Bi', 'Bj', 'Bk', 'Bl', 'Bm', 'Bn', 'Bo', 'Bp', 'Bq', 'Br', 'Bs', 'Bt', 'Bu', 'Bv', 'Bw', 'Bx', 'By']
n,k =raw_input().split()
n = int(n)
k = int(k)

ac = []
index = 0
for i in range(0,k-1):
	ac.append(text[index])
	index +=1
	pass

input = raw_input().split()
for i in range(k-1,n):
	if(input[i-k+1] == 'YES'):
		ac.append(text[index])
		index += 1
	else:
		#print ac[i+1-k],i+1-k
		ac.append(ac[i+1-k])
	pass
print ' '.join(ac)
