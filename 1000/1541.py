import sys
import re
input = sys.stdin.readline


equ = input()
val = list(map(int, re.split('[+-]', equ)))
op = []
for i in equ:
    if i == '+':
        op.append(0)
    elif i == '-':
        op.append(1)
ans = val[0]
chk = 0
for i in range(0, len(val) - 1):
    if op[i] == 1:
        chk = 1
    if chk == 1:
        ans -= val[i+1]
    else:
        ans += val[i+1]
print(ans)
