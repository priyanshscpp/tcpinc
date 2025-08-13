import math
for s in[*open(0)][2::2]:a=sorted(map(int,s.split()),key=lambda x:x%2);print(sum(math.gcd(2*x,y)>1for
(i,x)in enumerate(a)for y in a[:i]))