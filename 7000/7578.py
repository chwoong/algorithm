'''
 author: chw0501
 reference:
 created: 2020-12-26 05:52:43(UTC)
'''
import sys
# from collections import deque
# import heapq
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321

def update(pos):
    while pos <= n:
        fen[pos] += 1
        pos += (pos & -pos)

def query(pos):
    ret = 0
    while pos > 0:
        ret += fen[pos]
        pos -= (pos & -pos)
    return ret


n = int(input())
num = list(map(int, input().split()))
num2 = list(map(int, input().split()))
d = {}
ans = 0
order = [0 for _ in range(n + 1)]
for i, j in enumerate(num, 1):
    d[j] = i
for i in range(n):
    num[i] = d[num[i]]
    num2[i] = d[num2[i]]
    order[num2[i]] = i + 1
fen = [0 for _ in range(n + 1)]
for i in range(1, n + 1):
    p = order[i]
    ans += query(n) - query(p)
    update(p)
print(ans)