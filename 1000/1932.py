import sys
input = sys.stdin.readline

# dp[i][j] : (i,j)까지를 포함했을 때 그 경로상의 최댓값
size = int(input())
dp = [[0]*size for i in range(size)]
tri = [list(map(int, input().split())) for _ in range(size)]
dp[0][0] = tri[0][0]
for i in range(1, size):
    for j in range(i+1):
        if j == 0:
            dp[i][j] = dp[i-1][j] + tri[i][j]
        elif j == i:
            dp[i][j] = dp[i-1][j-1] + tri[i][j]
        else:
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j]
print(max(dp[size - 1]))
