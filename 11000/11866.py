import sys
# from collections import defaultdict
from collections import deque
# import bisect
input = sys.stdin.readline

n, k = map(int, input().split())
deq = deque()
for i in range(1, n+1):
    deq.append(i)
print('<', end='')
while n != 0:
    deq.rotate(-(k-1))
    print(deq.popleft(), end='')
    n -= 1
    print(', ' if n != 0 else '', end='')
print('>', end='')