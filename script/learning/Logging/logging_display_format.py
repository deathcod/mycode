import logging
'''
OUTPUT
DEBUG : This is debug message
INFO : This is a info message
WARNING : This is a warning message
'''
#logging.basicConfig(format = '%(levelname)s : %(message)s', level = logging.DEBUG)

'''
OUTPUT
2017-03-19 10:37:36,307 : This is debug message
2017-03-19 10:37:36,307 : This is a info message
2017-03-19 10:37:36,307 : This is a warning message
'''
logging.basicConfig(format = '%(asctime)s : %(message)s', level = logging.DEBUG)


logging.debug('This is debug message')
logging.info('This is a info message')
logging.warning('This is a warning message')