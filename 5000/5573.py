'''
 author: chw0501
 reference: https://kimcodingvv.github.io/BOJ-5573/
 created: 2020-12-20 09:12:13(UTC)
'''
import sys
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321

h, w, n = map(int, input().split())
path = [list(map(int, input().split())) for _ in range(h)]
# 각 좌표를 짝수 번 방문(0), 홀수 번 방문(1) 했는지 확인
dp = [[0 for _ in range(w + 1)] for __ in range(h + 1)]

dp[0][0] = n - 1
for i in range(h):
    for j in range(w):
        # 만약 (i,j) 를 방문했다면
        dp[i + 1][j] += (dp[i][j] // 2) + ((path[i][j] + 1) * dp[i][j]) % 2
        dp[i][j + 1] += (dp[i][j] // 2) + (path[i][j] * dp[i][j]) % 2

for i in range(h):
    for j in range(w):
        path[i][j] = (path[i][j] + dp[i][j]) % 2

r = 0
c = 0
while r < h and c < w:
    if path[r][c] == 1:
        c += 1
    else:
        r += 1
print(r + 1, c + 1)
