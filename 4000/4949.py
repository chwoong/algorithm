import sys
# from collections import defaultdict
# import bisect
input = sys.stdin.readline

while True:
    line = input().rstrip()
    if line == '.':
        break
    chk = True
    stack = []
    for c in line:
        if c == '(' or c == '[':
            stack.append(c)
        elif c == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                chk = False
        elif c == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                chk = False
    if stack:
        chk = False
    if chk:
        print("yes")
    else:
        print("no")
