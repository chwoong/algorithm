'''
 author: chw0501
 reference:
 created: 2020-12-24 08:28:57(UTC)
'''
import sys
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321

n = int(input())

board = [list(map(int, input().rstrip().split())) for _ in range(n)]
ans = [[1 for _ in range(n)] for __ in range(n)]
v = [[] for _ in range(1000001)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for i in range(n):
    for j in range(n):
        v[board[i][j]].append((i, j))
for i in range(1000001):
    for x, y in v[i]:
        for k in range(4):
            xx = x + dx[k]
            yy = y + dy[k]
            if n > xx >= 0 and n > yy >= 0 and board[xx][yy] > board[x][y]:
                ans[xx][yy] = max(ans[xx][yy], ans[x][y] + 1)
print(max(map(max, ans)))