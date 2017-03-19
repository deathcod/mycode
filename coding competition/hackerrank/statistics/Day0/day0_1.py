# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(raw_input())
int_list = [ int(i) for i in raw_input().split()]
dic = {}
vec = []
avg = 0
for x in int_list:
    avg += x
    vec.append(x)
    if x in dic:
        dic[x] +=1
        pass
    else:
        dic[x] =1
        pass
    pass
vec.sort()
print round(((1.0 * avg)/n),1)

if n%2 == 0:
    print round((1.0 * (vec[n/2 - 1] + vec[n/2]))/2, 1)
    pass
else:
    print vec[n/2 + 1]
    pass

max_count,min_val = -1,1e5

for i,val in dic.iteritems():
    if max_count <= val:
        max_count = val
        if min_val > i:
            min_val = i
            pass
        pass
    pass

print min_val