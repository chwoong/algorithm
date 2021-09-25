import sys
# from collections import defaultdict
# from collections import deque
# import bisect
input = sys.stdin.readline

n, m = map(int, input().split())
# dp[j]: j 비용을 이용해서 얻을 수 있는 최대 메모리양
dp = [0]*10101
mem = list(map(int, input().split()))
cost = list(map(int, input().split()))
for i in range(0, n):
    for j in range(10000, cost[i]-1, -1):
        dp[j] = max(dp[j], dp[j-cost[i]] + mem[i])
for i in range(0, 10001):
    if dp[i] >= m:
        print(i)
        break
