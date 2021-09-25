'''
 author: chw0501
 reference:
 created: 2020-12-19 09:11:40(UTC)
'''
import sys
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321


def dfs(r, c, idx):
    global num
    ans[idx] = max(ans[idx], num)
    if c >= n:
        r += 1
        c = (c + 1) % 2
    if r >= n:
        return
    if board[r][c] and not v1[r + c] and not v2[r - c + n]:
        num += 1
        v1[r + c] = v2[r - c + n] = True
        dfs(r, c + 2, idx)
        num -= 1
        v1[r + c] = v2[r - c + n] = False
    dfs(r, c + 2, idx)
    return


n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
ans = [0, 0]
v1 = [False for _ in range(2*n)]
v2 = [False for _ in range(2*n)]
num = 0
dfs(0, 0, 0)
v1 = [False for _ in range(2*n)]
v2 = [False for _ in range(2*n)]
num = 0
dfs(0, 1, 1)
print(sum(ans))