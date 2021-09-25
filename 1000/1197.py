import sys
# from collections import defaultdict
# from collections import deque
# import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
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
    par[u] = v


v, e = map(int, input().split())
par = [-1]*(v+1)
adj = []
for i in range(e):
    a, b, c = map(int, input().split())
    adj.append((c, a, b))
adj.sort()
ans = 0
for c, a, b in adj:
    if find(a) == find(b):
        continue
    else:
        ans += c
        merge(a, b)
print(ans)