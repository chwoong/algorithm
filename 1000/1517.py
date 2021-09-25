import sys
# from collections import defaultdict
# from collections import deque
import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)


def update(pos):
    pos += s
    while pos != 0:
        v[pos] += 1
        pos //= 2


def query(l, r):
    l += s
    r += s
    ret = 0
    while l <= r:
        if l % 2 == 1:
            ret += v[l]
            l += 1
        if r % 2 == 0:
            ret += v[r]
            r -= 1
        l //= 2
        r //= 2
    return ret


n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
for i in range(n):
    a[i] = bisect.bisect_left(b, a[i])
s = 1
while s < n:
    s *= 2
v = [0]*(2*s)
ans = 0
for i in range(n):
    if a[i] == 0:
        update(a[i])
        continue
    k = query(0, a[i])
    ans += (a[i]-k)
    update(a[i])
print(ans)