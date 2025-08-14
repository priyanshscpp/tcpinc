n=int(input())
l1=[]
for i in range (n):

    l1.append(input())

for i in range(n):
    if int(l1[i][0])+int(l1[i][1])+int(l1[i][2])==int(l1[i][3])+int(l1[i][4])+int(l1[i][5]):
        print("YES")
    else:
        print("NO")
print()