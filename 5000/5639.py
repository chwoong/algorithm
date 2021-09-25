import sys
# from collections import defaultdict
# from collections import deque
import bisect
input = sys.stdin.readline
#sys.setrecursionlimit(100000)

inord = []
for line in sys.stdin:
    inord.append(int(line.rstrip()))
ans = []
stack = []
stack.append((0, len(inord)))
while stack:
    i, length = stack.pop()
    if length <= 0:
        continue
    ans.append(inord[i])
    if length ==1:
        continue
    # i+1 ~(i+length-1) index 내에서 inord[i]보다 작은 것과 큰 것으로 나눠야함
    k = bisect.bisect_left(inord, inord[i], i+1, i+length)
    stack.append((i+1, k-i-1))
    stack.append((k, i+length-k))
ans.reverse()
print(*ans, sep='\n')