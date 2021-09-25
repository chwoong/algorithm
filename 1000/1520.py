import sys
# from collections import defaultdict
# from collections import deque
# import bisect
input = sys.stdin.readline


def solve(i, j):
    if i == m-1 and j == n-1:
        return 1
    if dp[i][j] != -1:
        return dp[i][j]
    else:
        dp[i][j] = 0
        for k in range(4):
            nx = i + dx[k]
            ny = j + dy[k]
            if nx >= 0 and ny >= 0 and nx < m and ny < n \
               and arr[i][j] > arr[nx][ny]:
                dp[i][j] += solve(nx, ny)
        return dp[i][j]


m, n = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(m)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
# dp[i][j]: (i,j)에서 시작해서 끝까지 가는 내리막길 개수
dp = [[-1]*n for _ in range(m)]
print(solve(0, 0))
