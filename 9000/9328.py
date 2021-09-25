'''
 author: chw0501
 reference:
 created: 2020-12-27 07:13:00(UTC)
'''
import sys
input = sys.stdin.readline
from collections import deque
# import heapq
# import bisect
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321


board = []
key = set()
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for _ in range(int(input())):
    ans = 0
    h, w = map(int, input().split())
    board = []
    key = set()
    for i in range(h):
        board.append(list(input().strip()))
    for k in list(input().strip()):
        if k != '0':
            key.add(k)
    visited = [[0 for i in range(w)] for j in range(h)]
    path = deque()
    lock = [[] for __ in range(26)]
    for i in range(h):
        for j in range(w):
            if i == 0 or i == h - 1 or j == 0 or j == w - 1:
                if board[i][j] == '.':
                    path.append((i, j))
                    visited[i][j] = 1
                elif 'a' <= board[i][j] <= 'z':
                    key.add(board[i][j])
                elif 'A' <= board[i][j] <= 'Z':
                    lock[ord(board[i][j]) - ord('A')].append((i, j))
                elif board[i][j] == '$':
                    path.append((i, j))
                    visited[i][j] = 1
                    ans += 1
    for k in key:
        for i, j in lock[ord(k) - ord('a')]:
            path.append((i, j))
            visited[i][j] = 1
        lock[ord(k) - ord('a')] = []
    while path:
        x, y = path.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < h and 0 <= ny < w and not visited[nx][ny]:
                if board[nx][ny] == '.':
                    path.append((nx, ny))
                    visited[nx][ny] = 1
                elif 'A' <= board[nx][ny] <= 'Z':
                    if chr(ord(board[nx][ny]) - ord('A') + ord('a')) in key:
                        path.append((nx, ny))
                        visited[nx][ny] = 1
                    else:
                        lock[ord(board[nx][ny]) - ord('A')].append((nx, ny))
                elif 'a' <= board[nx][ny] <= 'z':
                    key.add(board[nx][ny])
                    path.append((nx, ny))
                    visited[nx][ny] = 1
                    for i, j in lock[ord(board[nx][ny]) - ord('a')]:
                        path.append((i, j))
                        visited[i][j] = 1
                    lock[ord(board[nx][ny]) - ord('a')] = []
                elif board[nx][ny] == '$':
                    path.append((nx, ny))
                    visited[nx][ny] = 1
                    ans += 1

    print(ans)
