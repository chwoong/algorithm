import sys
# from collections import defaultdict
# from collections import deque
# import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
INF = 1000000000
MOD = 1000000003


n = int(input())
k = int(input())
# n-k+1 C n-2k+1  - n-k-1 C n-2k+1
dp = [[0 for _ in range(1001)] for _ in range(1001)]
if n < 2*k:
    print(0)
else:
    dp[0][0] = 1
    for i in range(1, n+1):
        for j in range(i+1):
            if j == 0 or j == n:
                dp[i][j] = 1
            else:
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD
    print((dp[n-k+1][n-2*k+1] - dp[n-k-1][n-2*k+1] + MOD)%MOD)