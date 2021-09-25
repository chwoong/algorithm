import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    x, q = input().split()
    x = int(x)
    for i in q:
        print(i * x, end='')
    print()
