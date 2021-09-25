import sys
# from collections import defaultdict
# from collections import deque
# import bisect
# from heapq import heappop, heappush
import math
# sys.setrecursionlimit(1000000)
input = sys.stdin.readline
INF = 1000000000
MOD = 1000000003


def find(i):
    if par[i] == -1:
        return i
    else:
        par[i] = find(par[i])
        return par[i]


def merge(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    par[u] = v


def dist(i, j):
    x1, y1 = pos[i]
    x2, y2 = pos[j]
    return math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))


n, m = map(int, input().split())
par = [-1]*(n+1)
pos = {}
for i in range(1, n+1):
    x, y = map(int, input().split())
    pos[i] = (x, y)
for _ in range(m):
    i, j = map(int, input().split())
    merge(i, j)
ans = 0
adj = []
for i in range(1, n+1):
    for j in range(i+1, n+1):
        adj.append((dist(i, j), i, j))
adj.sort()
for val, i, j in adj:
    if find(i) == find(j):
        continue
    ans += val
    merge(i, j)
print(format(ans, ".2f"))