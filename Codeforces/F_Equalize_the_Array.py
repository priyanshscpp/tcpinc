from collections import*
for _ in[*open(0)][2::2]:
    w=sorted(Counter([*_.split()]).values())
    o=len(w)
    print(sum(w)-max((o-i)*w[i]for i in range(o)))
