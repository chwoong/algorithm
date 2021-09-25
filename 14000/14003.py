import sys
# from collections import defaultdict
# from collections import deque
import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
# sys.setrecursionlimit(1000000)
input = sys.stdin.readline
INF = 1000000000
MOD = 1000000003


n = int(input())
arr = list(map(int, input().split()))
# dp[i]: i번째에서 시작하는 최대 부분 수열의 길이
dp = [0]*1000001
dp[n-1] = 1
v = [-arr[-1]]
for i in range(n-2, -1, -1):
    pos = bisect.bisect_left(v, -arr[i])
    if pos == len(v):
        v.append(-arr[i])
        dp[i] = len(v)
    else:
        v[pos] = -arr[i]
        dp[i] = pos+1
ans = len(v)
print(ans)
for i in range(n):
    if dp[i] == ans:
        print(arr[i], end=' ')
        ans = ans-1
