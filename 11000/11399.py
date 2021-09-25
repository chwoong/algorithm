import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
ans = 0
wait = 0
for i in arr:
    wait += i
    ans += wait
print(ans)