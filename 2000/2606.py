import sys
# from collections import defaultdict
# from collections import deque
#import bisect
input = sys.stdin.readline
#sys.setrecursionlimit(100000)


def find(i):
    if p[i] < 0:
        return i
    p[i] = find(p[i])
    return p[i]
    

def merge(i, j):
    i = find(i)
    j = find(j)
    if i == j:
        return
    p[i] += p[j]
    p[j] = i


n = int(input())
p = []
for i in range(n):
    p.append(-1)
for _ in range(int(input())):
    u, v = map(lambda x: int(x)-1, input().split())
    merge(u,v)
print(-p[find(0)]-1)
