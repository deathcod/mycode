#!/usr/bin/env python
# Simple Daikon-style invariant checker
# Andreas Zeller, May 2012
# Complete the provided code around lines 28 and 44
# Do not modify the __repr__ functions.
# Modify only the classes Range and Invariants,
# if you need additional functions, make sure
# they are inside the classes.

import sys
import math
import random

store_square_root = {}
store_square = {}

def square_root(x, eps = 0.00001):
    if x in store_square_root:
        y = store_square_root[x]
        return y
    assert x >= 0
    y = math.sqrt(x)
    assert abs(square(y) - x) <= eps
    store_square_root[x] = y
    return y
    
def square(x):
    if x in store_square:
        return store_square[x]
    z = x * x
    store_square[x] = z
    return z

# The Range class tracks the types and value ranges for a single variable.
class Range:
    def __init__(self):
        self.min  = None  # Minimum value seen
        self.max  = None  # Maximum value seen
    
    # Invoke this for every value
    def track(self, value):
        if self.min > value or self.min == None:
            self.min = value
        if self.max < value or self.max == None:
            self.max = value
            
    def __repr__(self):
        return repr(self.min) + ".." + repr(self.max)


# The Invariants class tracks all Ranges for all variables seen.
class Invariants:
    def __init__(self):
        # Mapping (Function Name) -> (Event type) -> (Variable Name)
        # e.g. self.vars["sqrt"]["call"]["x"] = Range()
        # holds the range for the argument x when calling sqrt(x)
        self.vars = {'square_root':{
                        'call':{'x':Range(),'eps':Range()},
                        'return':{'y':Range(),'ret':Range()}
                        },
                    'square':{
                        'call':{'x':Range()},
                        'return':{'ret':Range()}
                        }
                    }
        
    def track(self, frame, event, arg):
        fun_name = frame.f_code.co_name
        #print fun_name, event, frame.f_locals, arg
        if event == 'call':
            self.vars[fun_name][event]['x'].track(frame.f_locals['x'])
            if fun_name == 'square_root' :
                self.vars[fun_name][event]['eps'].track(frame.f_locals['eps'])
        elif event == 'return':
            self.vars[fun_name][event]['ret'].track(arg)
            if fun_name == 'square_root' :
                self.vars[fun_name][event]['y'].track(frame.f_locals['y'])
    
    def __repr__(self):
        # Return the tracked invariants
        s = ""
        for function, events in self.vars.iteritems():
            for event, vars in events.iteritems():
                s += event + " " + function + ":\n"
                # continue
                
                for var, range in vars.iteritems():
                    s += "    assert "
                    if range.min == range.max:
                        s += var + " == " + repr(range.min)
                    else:
                        s += repr(range.min) + " <= " + var + " <= " + repr(range.max)
                    s += "\n"
                
        return s

invariants = Invariants()
    
def traceit(frame, event, arg):
    invariants.track(frame, event, arg)
    return traceit

sys.settrace(traceit)
# Tester. Increase the range for more precise results when running locally
eps = 0.000001
for i in range(1, 2):
    r = int(random.random() * 10) # An integer value between 0 and 999.99
    z = square_root(r, eps)
    z = square(z)
sys.settrace(None)
print invariants

