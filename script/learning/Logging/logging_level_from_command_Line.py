import logging
import sys
'''
command line:
logging_level_from_command_line.py info
'''
loglevel = sys.argv[1]
print loglevel
numeric_level = getattr(logging, loglevel.upper(),None)
if not isinstance(numeric_level, int):
	raise ValueError('Invalid log level: %s' % loglevel)

#logging.basicConfig(level = numeric_level,)

#will update the logfile.
logging.basicConfig(level = numeric_level, filename = 'example.log', filemode = 'w')

