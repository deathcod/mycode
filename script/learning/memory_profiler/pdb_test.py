class MyObj(object):

    def __init__(self, num_loops):
        self.count = num_loops

    def go(self):
        for i in range(self.count):
            print i
        return 1/0

if __name__ == '__main__':
    MyObj(5).go()