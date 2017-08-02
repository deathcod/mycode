# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(raw_input())
ele = [ int(i) for i in raw_input().split()]
wei = [ int(i) for i in raw_input().split()]

_mul = 0
_sum = 0
for i in range(0,n):
    _mul += ele[i]*wei[i]
    _sum +=wei[i]
    pass

print round((1.0*(_mul)/_sum),1)