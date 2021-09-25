'''
 author: chw0501
 reference:
 created: 2020-12-19 07:20:53(UTC)
'''
import sys
import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF 987654321


def update(pos, val):
    pos += size
    while pos > 0:
        seg[pos] += val
        pos //= 2
    return


def query(l, r):
    l += size
    r += size
    ret = 0
    while l <= r:
        if l % 2 == 1:
            ret += seg[l]
            l += 1
        if r % 2 == 0:
            ret += seg[r]
            r -= 1
        l //= 2
        r //= 2
    return ret


seg = [0]
size = 1

for _ in range(int(input())):
    n = int(input())
    while size < n:
        size *= 2
    island = []
    seg = [0] * (2*size)
    comp_x = []
    comp_y = []
    for i in range(n):
        x, y = map(int, input().split())
        island.append((x, -y))
        comp_x.append(x)
        comp_y.append(y)
    island.sort()
    comp_x.sort()
    comp_y.sort()
    # 좌표 압축
    for i in range(n):
        x, y = island[i]
        x = bisect.bisect_left(comp_x, x)
        y = bisect.bisect_left(comp_y, -y)
        island[i] = (x, -y)
    # y좌표를 저장한 세그먼트 트리로 누적 합 구하기
    ans = 0
    for i in range(n):
        x, y = island[i]
        ans += query(-y, n-1)
        update(-y, 1)
    print(ans)
