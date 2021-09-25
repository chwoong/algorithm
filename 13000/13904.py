import sys
input = sys.stdin.readline

n = int(input())
visited = [0]*1001
arr = []
for i in range(n):
    x, y = map(int, input().split())
    arr += [(y, x)]
arr.sort(reverse=True)
ans = 0
for p in arr:
    for date in range(p[1], 0, -1):
        if visited[date] == 0:
            visited[date] = True
            ans += p[0]
            break
print(ans)
