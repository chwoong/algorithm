import sys
# from collections import defaultdict
# from collections import deque
# import bisect
input = sys.stdin.readline
sys.setrecursionlimit(100000)

n = int(input())
inord = list(map(int, input().split()))
ind = [0]*(n+1)
for i in range(n):
    ind[inord[i]] = i
postord = list(map(int, input().split()))
preord = []
stack = []
stack.append((0, 0, n-1))
while len(stack) != 0:
    i, j, length = stack.pop()
    root = postord[j+length]
    if length < 0:
        continue
    preord.append(root)
    val = ind[root]
    stack.append((val+1, j+val-i, length-val+i-1))
    stack.append((i, j, val-i-1))

print(' '.join(map(str, preord)))
