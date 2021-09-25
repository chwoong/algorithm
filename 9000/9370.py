import sys
# from collections import defaultdict
# from collections import deque
# import bisect
from queue import PriorityQueue
input = sys.stdin.readline
# sys.setrecursionlimit(100000)

INF = 100000000
# each test case
aa = int(input())
for _ in range(aa):
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())
    adj = [[] for i in range(n+1)]
    for i in range(m):
        a, b, d = map(int, input().split())
        if (a, b) == (g, h) or (a, b) == (h, g):
            d = 2*d-1
        else:
            d = 2*d
        adj[a].append((b, d))
        adj[b].append((a, d))
    dists = [INF]*(n+1)
    dists[s] = 0
    pq = PriorityQueue()
    # s에서 다익스트라
    pq.put((0, s))
    while not pq.empty():
        cost, here = pq.get()
        cost = cost
        if dists[here] < cost:
            continue
        for point, dist in adj[here]:
            if cost+dist < dists[point]:
                dists[point] = cost + dist
                pq.put((dists[point], point))
    ans = []
    for i in range(t):
        x = int(input())
        if dists[x] % 2 == 1:
            ans.append(x)
    ans.sort()
    print(*ans)