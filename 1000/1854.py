'''
 author: chw0501
 reference:
 created: 2020-12-24 08:28:57(UTC)
'''
import sys
# import bisect
from collections import deque
import heapq
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321

n, m, k = map(int, input().split())
adj = [[] for _ in range(n + 1)]
dist = [[] for _ in range(n + 1)]
heapq.heappush(dist[1], (0, 0))

for _ in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
dq = deque()
dq.append((1, 0))
while dq:
    pos, d = dq.popleft()
    for nextpos, cost in adj[pos]:
        allcost = cost + d
        if dist[nextpos]:
            # nextpos로 가는 경로 중 최댓값
            a = dist[nextpos][0][1]
            if len(dist[nextpos]) < k:
                heapq.heappush(dist[nextpos], (-allcost, allcost))
                dq.append((nextpos, allcost))
            elif allcost < a:
                heapq.heappop(dist[nextpos])
                heapq.heappush(dist[nextpos], (-allcost, allcost))
                dq.append((nextpos, allcost))
        else:
            heapq.heappush(dist[nextpos], (-allcost, allcost))
            dq.append((nextpos, allcost))
for i in range(1, n + 1):
    if not dist[i]:
        print(-1)
    elif len(dist[i]) < k:
        print(-1)
    else:
        print(dist[i][0][1])
