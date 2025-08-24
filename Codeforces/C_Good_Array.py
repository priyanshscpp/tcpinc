#Trying the python code 
# Om namo narayanaya

input()
a=[*map(int ,input().split())]
s,b =sum(a),sorted(a)[-2:]
k=[x for x,y in enumerate(a,1)if s-y==2*b[y!=b[1]]
]
print(len(k),*k)