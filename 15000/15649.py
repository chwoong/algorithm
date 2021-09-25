# num: 지금까지 check된 개수
def dfs(num):
    if num == m:
        for i in res:
            print(i, end=' ')
        print()
        return
    for j in range(1, n+1):
        if visited[j] == 1:
            continue
        else:
            visited[j] = 1
            res.append(j)
            dfs(num+1)
            res.pop()
            visited[j] = 0


n, m = map(int, input().split())
res = []
visited = [0] * (n+1)
dfs(0)
