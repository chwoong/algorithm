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
            # i ~ x  와  x+1 ~ j로 나눔
            dp[i][j] = min(solve(i, x)+solve(x+1, j)+s[j]-s[i-1], dp[i][j])
        return dp[i][j]


for i in range(int(input())):
    k = int(input())
    arr = list(map(int, input().split()))
    # dp[i][j]: i번째부터 j번째까지 파일의 합치는데 필요한 최소 비용
    dp = [[0]*(k+1) for _ in range(k+1)]
    # s[i]: 1~i까지의 파일 크기 합
    s = [0]
    for j in range(k):
        s.append(s[-1]+arr[j])
    print(solve(1, k))

