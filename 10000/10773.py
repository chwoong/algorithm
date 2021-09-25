import sys
# from collections import defaultdict
# import bisect
input = sys.stdin.readline

k = int(input())
res = []
for _ in range(k):
    a = int(input())
    if a != 0:
        res.append(a)
    else:
        res.pop()
print(sum(res))