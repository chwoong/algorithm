import sys
input = sys.stdin.readline

n = int(input())
grape = []
for i in range(n):
    x = int(input())
    grape.append(x)
# dp[i][0]: i 안마심
# dp[i][1]: i-1 안마시고 i마심
# dp[i][2]: i-1, i를 마심
dp = [[0]*3 for _ in range(n)]
dp[0][0] = 0
dp[0][1] = dp[0][2] = grape[0]
for i in range(1, n):
    dp[i][0] = max(dp[i-1])
    dp[i][1] = dp[i-1][0] + grape[i]
    dp[i][2] = dp[i-1][1] + grape[i]
print(max(max(dp)))
