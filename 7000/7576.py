import sys
# from collections import defaultdict
from collections import deque
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
m, n = map(int, input().split())
tomato = []
visited = [[False]*m for _ in range(n)]
for _ in range(n):
    line = list(map(int, input().split()))
    tomato.append(line)
dq = deque()
for i in range(n):
    for j in range(m):
        if tomato[i][j] == 1:
            dq.append((i, j))
ans = 0
while dq:
    size = len(dq)
    chk = False
    for _ in range(size):
        i, j = dq.popleft()
        for k in range(4):
            ni = i + dx[k]
            nj = j + dy[k]
            if n > ni >= 0 and m > nj >= 0 and tomato[ni][nj] == 0 \
               and not visited[ni][nj]:
                tomato[ni][nj] = 1
                dq.append((ni, nj))
                visited[ni][nj] = True
                chk = True
    if chk:
        ans += 1

for i in range(n):
    for j in range(m):
        if tomato[i][j] == 0:
            ans = -1
print(ans)
