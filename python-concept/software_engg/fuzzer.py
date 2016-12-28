file_list = ["CR.pdf"]

app = "/usr/share/applications/AdobeReader.desktop"             # link to adobe reader
fuzz_output = "fuzz.pdf"

Fuzz_factor = 250
num_tests = 10000

import math
import random
import string
import subprocess
import time

for i in range(num_tests):

	file_choice = random.choice(file_list)
	#app = random.choice(apps)

	buf = bytearray(open(file_choice,'rb').read())

	numwrites = random.randrange(math.ceil((float(len(buf)) / Fuzz_factor))) + 1

	#Charlie miller code starts

	for j in range(numwrites):
		rbyte = random.randrange(256)
		rn = random.randrange(len(buf))
		buf[rn] = "%c" % (rbyte)

	# code ends
	open(fuzz_output, 'wb' ).write(buf)

	process = subprocess.Popen([app, fuzz_output])

	time.sleep(1)
	crashed = process.poll()
	if not crashed:
		process.terminate()

	