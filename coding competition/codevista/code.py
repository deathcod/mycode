def gcd(a,b):
	try:
		if a<b:
			a,b=b,a
			pass
		local_flag=1
		for i in range(2,b+1):
			if a%i==0 and b%i==0:
				local_flag=i
				pass
			pass
		return local_flag
		pass
	except:
		return "-1#@$%$#@"

def lcm(x,y):
	try:
		x=int(x)
		y=int(y)
		return (x*y)/gcd(x,y)
		pass
	except:
		return "-1#@$%$#@"

def game_started(x,Player):
	try:
		if Player==1:
			x=x.replace('Sally ','')
		else:
			x=x.replace('Darrell ','')
		if x=='':
			return 0
		x=x.split(',')
		length=len(x)
		ac=x[0]
		for i in range(1,length):
			ac=lcm(ac,x[i])
			pass
		return ac
		pass
	except:
		return "-1#@$%$#@"

def checking(x,Player):
	try:
		if Player==2:
			x=x.replace('A Sally ','')
		else:
			x=x.replace('A Darrell ','')
		if x=='PASS':
			return 0
		return int(x)
		pass
	except:
		return "-23#@$#@$"
def main():
	try:
		Sally=0
		Darrell=0
		flag=0
		Player=0
		Play=0
		n=input()
		n=int(n)
		while n>0:
			x=input()
			if Player==0:
				if 'Sally' in x:
					Player=1
				else:
					Player=2
				Play=Player
			if flag==0:
				value1=int(game_started(x,Player))
				if value1==0:
					print ('Invalid Input')
					return 0
				else:
					print (x.replace(' ','\'s question is: '))
					pass
				flag=1
				pass
			elif flag==1:
				x=x.strip(' ')
				value2=checking(x,Player)
				local_value=0
				if value2==0:
					print ('Question is PASSed')
					print ('Answer is: '+str(value1))
				elif value2==value1:
					print ('Correct Answer')
					local_value=10
					if 'Sally' in x:
						Sally+=10
					else:
						Darrell+=10
				else:
					print ('Wrong Answer')
				if 'Sally' in x:
					print ('Sally: '+str(local_value)+'points')
				else:
					print ('Darrell: '+str(local_value)+'points')
				flag=0
				if Player==1:
					Player=2
					pass
				else:
					Player=1
			n-=1
			pass
		print ('Total Points:')
		Sally1= 'Sally: '+str(Sally)+'points'
		Darrell1= 'Darrell: '+str(Darrell)+'points'
		if Play==1:
			print (Sally1+"\n"+Darrell1)
		else:
			print (Darrell1+"\n"+Sally1)
		if Sally==Darrell:
			print ('Game Result: Draw',)
		elif Sally>Darrell:
			print ('Game Result: Sally is winner',)
		else:
			print ('Game Result: Darrell is winner',)
		pass
	except:
		print ('Invalid Input')
		return 0
main()