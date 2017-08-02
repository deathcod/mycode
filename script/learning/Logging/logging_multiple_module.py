import logging

def fun():
	print "This is the function"
	pass

def main():
	logging.basicConfig(filename = 'example.log', level = logging.INFO)
	logging.info('Started fun')
	fun()
	logging.info('Finished fun')

if __name__ == '__main__':
	main()