t=int(input())
while(t>0):
    t=t-1
    c=0
    l=list(map(int,input().split()))
    for i in l[1::]:
        if(i>l[0]):
            c=c+1
    print(c)