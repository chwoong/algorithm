import sys
input = sys.stdin.readline

num = int(input())
seq = input().rstrip()
ans = 0
for i in range(num):
    ans += int(seq[i])
print(ans)