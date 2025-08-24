import math
import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    l1 = list(map(int, input().split()))

    l2 = [abs(j + 1 - l1[j]) for j in range(n)]
    l2 = [x for x in l2 if x != 0] 

    j = l2[0]
    for k in set(l2):
        j = math.gcd(j, k)

    print(j)
