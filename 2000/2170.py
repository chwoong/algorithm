'''
 author: chw0501
 reference:
 created: 2020-12-22 07:08:26(UTC)
'''
import sys
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321

n = int(input())
stick = sorted([sorted(list(map(int, input().split()))) for _ in range(n)])
s = -1000000001
e = -1000000001
ans = 0
for i, j in stick:
    if i > e:
        s = i
        e = j
        ans += (e-s)
    elif i <= e:
        ans += max(0, j - e)
        e = max(e, j)
print(ans)