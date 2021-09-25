n = int(input())
arr = list(map(int, input().split()))
ans = arr[0]
v = arr[0]
for i in range(1, n):
    if v + arr[i] > 0:
        v += arr[i]
        ans = max(ans, v)
    else:
        ans = max(ans, arr[i])
        v = 0
print(ans)
