import sys
# from collections import defaultdict
# import bisect
input = sys.stdin.readline

n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)
stack = [0]
ans = []
chk = True
# k까지 넣었음
k = 0
for i in range(n):
    if arr[i] > stack[-1]:
        for j in range(k+1, arr[i]+1):
            stack.append(j)
            ans.append('+')
            k = k+1
        ans.append('-')
        stack.pop()
    elif arr[i] == stack[-1]:
        ans.append('-')
        stack.pop()
    else:
        chk = False
        break
if chk:
    print(*ans, sep='\n')
else:
    print("NO")
