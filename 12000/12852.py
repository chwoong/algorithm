import sys
# from collections import defaultdict
# from collections import deque
# import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
input = sys.stdin.readline
INF = 1000000000
MOD = 1000000003


n = int(input())
# dp[i]: i를 1로 만드는 최소 횟수
dp = [0]*1000001
dp[1] = 0
dp[2] = 1
dp[3] = 1
for i in range(2, n+1):
    if dp[i] == 0:
        dp[i] = dp[i-1]+1
        if i % 3 == 0:
            dp[i] = min(dp[i], dp[i//3]+1)
        if i % 2 == 0:
            dp[i] = min(dp[i], dp[i//2]+1)
    else:
        continue
print(dp[n])
while n != 1:
    print(n, end=' ')
    if n % 3 == 0 and dp[n//3] == dp[n]-1:
        n = n // 3
        continue
    if n % 2 == 0 and dp[n//2] == dp[n]-1:
        n = n // 2
        continue
    n = n-1
print(1)
