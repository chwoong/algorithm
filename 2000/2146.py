'''
 author: chw0501
 reference:
 created: 2020-12-26 06:07:10(UTC)
'''
import sys
input = sys.stdin.readline
# from collections import deque
# import heapq
# import bisect
sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321


def dfs(i, j, col):
    visited[i][j] = 1
    board[i][j] = col
    for k in range(4):
        ni = i + dx[k]
        nj = j + dy[k]
        if 0 <= ni < n and 0 <= nj < n and not visited[ni][nj] and board[ni][nj] != 0:
            dfs(ni, nj, col)


def solve():
    chk1 = 0
    chk2 = 0
    ans = 0
    tmp = True
    while tmp:
        newboard = [[0 for _ in range(n)] for __ in range(n)]
        for i in range(n):
            for j in range(n):
                if newboard[i][j] == 0 and board[i][j] != 0:
                    for k in range(4):
                        ni = i + dx[k]
                        nj = j + dy[k]
                        if 0 <= ni < n and 0 <= nj < n:
                            if board[ni][nj] == 0:
                                board[ni][nj] = board[i][j]
                                newboard[ni][nj] = 1
                            # 다리가 이어짐
                            elif board[ni][nj] != board[i][j]:
                                if newboard[ni][nj] == 1:
                                    chk1 = 1
                                else:
                                    chk2 = 1
                                tmp = False
        if tmp:
            ans += 1
    if chk2:
        return 2 * ans
    elif chk1:
        return 2 * ans + 1


n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[0 for _ in range(n)] for __ in range(n)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
c = 1
for i in range(n):
    for j in range(n):
        if not visited[i][j] and board[i][j] != 0:
            dfs(i, j, c)
            c += 1
print(solve())