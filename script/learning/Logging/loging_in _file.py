import logging
logging.basicConfig(filename = 'log.txt', level = logging.DEBUG)
logging.debug('This is a debig message will be written on a file')
logging.info('This is an info message should be written to a file')
logging.warning('This is a warning message')