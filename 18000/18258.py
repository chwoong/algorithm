import sys
# from collections import defaultdict
from collections import deque
# import bisect
input = sys.stdin.readline

n = int(input())
size = 0
deq = deque()
for i in range(n):
    op = input().split()
    if op[0] == 'push':
        deq.append(int(op[1]))
        size += 1
    elif op[0] == 'pop':
        print(deq[0] if size != 0 else -1)
        if size != 0:
            deq.popleft()
            size -= 1
    elif op[0] == 'size':
        print(size)
    elif op[0] == 'empty':
        print(1 if size == 0 else 0)
    elif op[0] == 'front':
        print(deq[0] if size != 0 else -1)
    elif op[0] == 'back':
        print(deq[-1] if size != 0 else -1)
