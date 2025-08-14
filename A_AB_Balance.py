for i in range(int(input())):
    a=input()
    if a[-1]==a[0]:
        print(a)
    else:
        print(a[-1]+a[1:])