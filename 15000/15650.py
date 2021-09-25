def dfs(i, num):
    if num == m:
        print(*res)
        return
    elif i == n+1:
        return
    for j in range(i, n+1):
        res.append(j)
        dfs(j+1, num+1)
        res.pop()


n, m = map(int, input().split())
res = []
dfs(1, 0)
