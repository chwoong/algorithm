import sys
# from collections import defaultdict
# from collections import deque
# import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
input = sys.stdin.readline
# sys.setrecursionlimit(100000)


INF = 1000000000


def solve(i, j, k):
    ret = dp[i][j][k]
    if ret != -1:
        return ret
    if i == n:
        if j == k:
            dp[i][j][k] = INF
            ret = dp[i][j][k]
        else:
            dp[i][j][k] = 0
            ret = dp[i][j][k]
        return ret
    # k를 0,1,2로 바꿔보자
    ret = INF
    for col in range(3):
        if col != k:
            ret = min(ret,cost[i+1][col]+solve(i+1, j, col))
    dp[i][j][k] = ret
    return ret
    
n = int(input())
cost = [[0 for _ in range(3)] for _ in range(n+1)]
# dp[i][j][k]: 1번집을 j로 칠하고 i번집을 k로 칠했을 때 앞으로 칠하는 비용의 최솟값
dp = [[[-1 for _ in range(3)]for _ in range(3)] for _ in range(n+1)]
for i in range(1, n+1):
    cost[i][0], cost[i][1], cost[i][2] = map(int, input().split())
ans = INF
for i in range(3):
    ans = min(ans, cost[1][i]+solve(1,i,i))
print(ans)

