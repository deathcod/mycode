# Regression Testing
# ------------------
# The goal of this problem is for you to write a regression tester
# for the Queue class.
# 
# Begin by finding and fixing all of the bugs in the Queue class. Next,
# define the function regression_test to take in a list of enqueue inputs
# and dequeue indicators (the returned list of the previous problem) and
# repeat those method calls using the fixed Queue.
# 
# That is, after fixing the Queue class, create a new Queue instance,
# and call the method corresponding to the indicator in the list
# for each item in the list:
# 
# Call the enqueue function whenever you come across an integer, using that
#     integer as the argument.
# Call the dequeue function whenever you come across the 'dq' indicator.

import array
import random

# Fix this Queue class
class Queue:
    
    def __init__(self,size_max):
        assert size_max > 0
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self,x):
        if self.size == self.max:
            return False
        self.data[self.tail] = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size == 0:
            return None
        x = self.data[self.head]
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x

    def checkRep(self):            
        assert self.tail >= 0
        assert self.tail < self.max
        assert self.head >= 0
        assert self.head < self.max
        if self.tail > self.head:
            assert (self.tail-self.head) == self.size
        if self.tail < self.head:
            assert (self.head-self.tail) == (self.max-self.size)
        if self.head == self.tail:
            assert (self
                    .size==0) or (self.size==self.max)


# An example list of enqueue integers and dequeue indicators
inputs = [(592726, 0), (36821, 0), (732412, 0), (442859, 0), 
        (292906, 0), (268271, 0), (601196, 0), (293748, 0), 
        (705217, 0), (558577, 1), (372627, 1), ('dq', 1),
        ('dq', 1), ('dq', 1), ('dq', 1), ('dq', 1), ('dq', 1), 
        ('dq', 1), ('dq', 1), ('dq', 1), ('dq', 1), ('dq', 1), 
        (525651, 0), (379501, 0), (701381, 0), (718316, 0), 
        (529843, 0), ('dq', 1), (80337, 0), (598147, 0), 
        (722157, 0), ('dq', 1), ('dq', 1), ('dq', 1), (51801, 0),
        ('dq', 1), (156896, 0), (450950, 0), ('dq', 1), ('dq', 1), 
        ('dq', 1), (212793, 0), (740903, 0), ('dq', 1), (286573, 0), 
        ('dq', 1), ('dq', 1), (395448, 0), (336521, 0), (893927, 0), 
        ('dq', 1), (629340, 0), ('dq', 1), (327049, 0), (569763, 0), 
        ('dq', 1), (327350, 0), (718809, 0), ('dq', 1), ('dq', 1), 
        ('dq', 1), ('dq', 1), ('dq', 1), (316971, 0), (198386, 0)]


# Write a regression tester for the Queue class
def regression_test():
    size = 10
    q = Queue(size)
    local_queue = []
    new_input = []
    for index,i in enumerate(inputs):
        try:
            if type(i[0]) == int :
                if len(local_queue) == size:
                    assert q.enqueue(i[0]) == False
                else:
                    local_queue.append(i[0])
                    assert q.enqueue(i[0]) == True
                    pass
                pass
            else:
                if len(local_queue) == 0:
                    assert q.dequeue() == None
                else:
                    out = local_queue.pop(0)
                    assert q.dequeue() == out
                    pass
                pass
        except Exception,e:
            print index,i,e
            
regression_test()
                
            