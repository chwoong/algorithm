import sys
# from collections import defaultdict
from collections import deque
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)


def bfs(curr):
    dq = deque()
    visited[curr] = True
    dq.append(curr)
    while len(dq):
        size = len(dq)
        for _ in range(size):
            here = dq.popleft()
            for nextp, d in adj[here]:
                if visited[nextp] == False:
                    dist[nextp] = dist[here] + d
                    visited[nextp] = True
                    dq.append(nextp)
    

v = int(input())
adj = [[] for _ in range(v+1)]
for _ in range(v):
    line = list(map(int, input().split()))
    num = len(line) // 2
    for i in range(1, num):
        adj[line[0]].append((line[2*i-1],line[2*i]))

visited = [False]*(v+1)
dist = [0] *(v+1)
bfs(1)
tmp = dist.index(max(dist))
visited = [False]*(v+1)
dist =[0]*(v+1)
bfs(tmp)
print(max(dist))