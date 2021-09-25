import sys
# from collections import defaultdict
from collections import deque
# import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
# sys.setrecursionlimit(1000000)
input = sys.stdin.readline
INF = 1000000000
MOD = 1000000003


n = int(input())
m = int(input())
adj = [[] for _ in range(n+1)]
inv = [[] for _ in range(n+1)]
for i in range(m):
    u, v, c = map(int, input().split())
    adj[u].append((v, c))
    inv[v].append((u, c))
st, en = map(int, input().split())
# st에서 시작하는 모든 점까지의 최소거리 계산하자
dist = [INF]*(n+1)
dq = deque()
dist[st] = 0
dq.append((st, 0))
# 다익스트라
while dq:
    here, c = dq.popleft()
    if dist[here] < c:
        continue
    for there, cost in adj[here]:
        if dist[there] > cost+dist[here]:
            dist[there] = cost+dist[here]
            dq.append((there, dist[there]))
print(dist[en])
path = [en]
while path[-1] != st:
    here = path[-1]
    for curr, d in inv[here]:
        if dist[curr] + d == dist[here]:
            path.append(curr)
            break
print(len(path))
path.reverse()
print(*path)