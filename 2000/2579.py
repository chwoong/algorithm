import sys
input = sys.stdin.readline

n = int(input())
score = [0]
dp = [[0]*2 for _ in range(400)]
# dp[i][0]: i�� ��� i-1�� �ȹ��
# dp[i][1]: i�� i-1 �Ѵ� ���
for _ in range(n):
    score.append(int(input()))
dp[1][0] = dp[1][1] = score[1]
for i in range(2, n+1):
    dp[i][0] = max(dp[i-2]) + score[i]
    dp[i][1] = dp[i-1][0] + score[i]
print(max(dp[n]))
