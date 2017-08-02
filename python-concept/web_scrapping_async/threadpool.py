from concurrent import futures

class FooError(Exception):
	pass


def foo(x=3, y=4):
	if x > y:
		raise FooError
	return y-x


with futures.ThreadPoolExecutor() as pool:
	running = [pool.submit(foo, 5, 8),
				pool.submit(foo, 6, 9)]

	for future in futures.as_completed(running):
		data = future.result()
		print data
		pass

	pass