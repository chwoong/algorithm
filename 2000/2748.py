import sys
input = sys.stdin.readline

n = int(input())
m = [0, 1]
for i in range(2, n+1):
    m[i % 2] = (m[0] + m[1])
print(m[n % 2])
