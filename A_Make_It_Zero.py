import sys
input = sys.stdin.readline

for i in range(int(input())):
    n=int(input())
    l1=list(map(int,input().split()))
    if n%2==0:
        print(2)
        print(1,n)
        print(1,n)
    else:
        print(4)
        print(1,2)
        print(1,2)
        print(2,n)
        print(2,n)

        