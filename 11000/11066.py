import sys
# from collections import defaultdict
# from collections import deque
# import bisect
input = sys.stdin.readline


def solve(i, j):
    if dp[i][j] != 0:
        return dp[i][j]
    elif i == j:
        dp[i][j] = 0
        return 0
    elif i+1 == j:
        dp[i][j] = arr[i-1]+arr[j-1]
        return dp[i][j]
    else:
        dp[i][j] = 500*500*10000
        for x in range(i, j):
            # i ~ x  ��  x+1 ~ j�� ����
            dp[i][j] = min(solve(i, x)+solve(x+1, j)+s[j]-s[i-1], dp[i][j])
        return dp[i][j]


for i in range(int(input())):
    k = int(input())
    arr = list(map(int, input().split()))
    # dp[i][j]: i��°���� j��°���� ������ ��ġ�µ� �ʿ��� �ּ� ���
    dp = [[0]*(k+1) for _ in range(k+1)]
    # s[i]: 1~i������ ���� ũ�� ��
    s = [0]
    for j in range(k):
        s.append(s[-1]+arr[j])
    print(solve(1, k))

