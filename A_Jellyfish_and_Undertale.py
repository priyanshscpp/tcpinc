#Trying python programming 
for _ in range(int(input())):
    a,b,n=map(int,input().split())
    for i in input().split():
        b+=min(a-1,int(i))
    print(b)