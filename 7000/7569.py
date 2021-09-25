import sys
# from collections import defaultdict
from collections import deque
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)

dx = [-1, 0, 1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]
m, n, h = map(int, input().split())
tomato = []
visited = [[[False]*m for _ in range(n)] for _ in range(h)]
for _ in range(h):
    layer = []
    for _ in range(n):
        line = list(map(int, input().split()))
        layer.append(line)
    tomato.append(layer)
dq = deque()
for i in range(n):
    for j in range(m):
        for k in range(h):
            if tomato[k][i][j] == 1:
                dq.append((i, j, k))
ans = 0
while dq:
    size = len(dq)
    chk = False
    for _ in range(size):
        i, j, k = dq.popleft()
        for a in range(6):
            ni = i + dx[a]
            nj = j + dy[a]
            nk = k + dz[a]
            if n > ni >= 0 and m > nj >= 0 and h > nk >= 0 and \
               tomato[nk][ni][nj] == 0 and not visited[nk][ni][nj]:
                tomato[nk][ni][nj] = 1
                dq.append((ni, nj, nk))
                visited[nk][ni][nj] = True
                chk = True
    if chk:
        ans += 1

for i in range(n):
    for j in range(m):
        for k in range(h):
            if tomato[k][i][j] == 0:
                ans = -1
print(ans)
