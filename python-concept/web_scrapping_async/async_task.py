"""aiohttp-based client to retrieve web pages.
"""

import asyncio
from contextlib import closing
import time

@asyncio.coroutine
def func(wait = 0):
    yield from asyncio.sleep(wait)
    return 'I waited for %s' % str(wait)

def get_multiple_pages(host, waits, port=8000, show_time=True):
    """Get multiple pages.
    """
    tasks = []
    pages = []
    start = time.perf_counter()
    with closing(asyncio.get_event_loop()) as loop:
        for wait in waits:
            tasks.append(func(wait))
        pages = loop.run_until_complete(asyncio.gather(*tasks))
    duration = time.perf_counter() - start
    sum_waits = sum(waits)
    if show_time:
        msg = 'It took {:4.2f} seconds for a total waiting time of {:4.2f}.'
        print(msg.format(duration, sum_waits))
    return pages


if __name__ == '__main__':
 
    def main():
        """Test it.
        """
        pages = get_multiple_pages(host='http://127.0.0.1', port='5000',
                                   waits=[1, 5, 3, 2])
        for page in pages:
            print(page)

    main()