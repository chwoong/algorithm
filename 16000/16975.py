import sys
# from collections import defaultdict
# from collections import deque
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)


def update(l, r, k):
    l += s
    r += s
    while l <= r:
        if l % 2 == 1:
            seg[l] += k
            l += 1
        if r % 2 == 0:
            seg[r] += k
            r -= 1
        l //= 2
        r //= 2


def query(pos):
    pos += s
    ret = 0
    while pos != 0:
        ret += seg[pos]
        pos //= 2
    return ret


n = int(input())
a = list(map(int, input().split()))
s = 1
while s < n:
    s *= 2
seg = [0]*(2*s)
for i in range(int(input())):
    line = list(map(int, input().split()))
    if line[0] == 1:
        update(line[1]-1, line[2]-1, line[3])
    else:
        print(a[line[1]-1]+query(line[1]-1))

