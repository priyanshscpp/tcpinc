#testing python code
n = int(input())
a=input()
if (n-1)%2==0:
    c = ''
    i = n - 2
    while i % 2 != 0 and i > 0:
        c = c + a[i]
        i = i - 2
    i = 0
    while i % 2 == 0 and i < n:
        c = c + a[i]
        i = i + 2
else:
    c = ''
    i = n - 2
    while i % 2 == 0 and i >= 0:
        c = c + a[i]
        i = i - 2

    i = 1
    while i % 2 != 0 and i < n:
        c = c + a[i]
        i = i + 2
print(c)