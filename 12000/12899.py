import sys
# from collections import defaultdict
# from collections import deque
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)

# x 번쨰로 작은 수를 반환한다.
def xth(x):
    pos = 1
    while pos < s:
        if seg[pos*2] < x:
            x -= seg[pos*2]
            pos = pos*2+1
        else:
            pos = pos*2
    return pos-s+1


def update(pos, k):
    pos += s
    while pos != 0:
        seg[pos] += k
        pos //= 2


s = 2097152
seg = [0]*(2*s)
for i in range(int(input())):
    t, x = map(int, input().split())
    if t == 1:
        update(x-1, 1)
    else:
        val = xth(x)
        print(val)
        update(val-1, -1)
