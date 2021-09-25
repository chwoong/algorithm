import sys
# from collections import defaultdict
from collections import deque
# import bisect
# from heapq import heappop, heappush
# from queue import PriorityQueue
# sys.setrecursionlimit(1000000)
input = sys.stdin.readline
INF = 1000000000
MOD = 1000000003

n, k = map(int, input().split())
path = [-1]*100001
dq = deque()
dq.append(k)

while dq:
    here = dq.popleft()
    curr = here+1
    if curr <= 100000 and path[curr] == -1:
        path[curr] = here
        dq.append(curr)
    curr = here-1
    if curr >= 0 and path[curr] == -1:
        path[curr] = here
        dq.append(curr)
    if here % 2 == 0:
        curr = here // 2
        if curr >= 0 and path[curr] == -1:
            path[curr] = here
            dq.append(curr)
ans = [n]
while ans[-1] != k:
    ans.append(path[ans[-1]])
print(len(ans)-1)
print(*ans)
