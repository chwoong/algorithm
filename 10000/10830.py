import sys
input = sys.stdin.readline

n, b = map(int, input().split())
one = [[0]*n for _ in range(n)]
for i in range(n):
    one[i][i] = 1
arr = [[*map(int, input().split())] for _ in range(n)]
for i in range(n):
    for j in range(n):
        arr[i][j] %= 1000


def mul(ma, mb):
    x = list(ma)
    y = list(mb)
    ret = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                ret[i][j] += x[i][k] * y[k][j]
                ret[i][j] %= 1000
    return ret


def solve(i):
    if i == 0:
        return one
    if i == 1:
        return arr
    res = solve(i // 2)
    ans = mul(res, res)
    ans = mul(ans, solve(i % 2))
    return ans


ans = solve(b)
for i in range(n):
    print(*ans[i])
