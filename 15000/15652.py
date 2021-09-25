def solve(s, num):
    if num == m:
        print(*res)
        return
    for i in range(s, n+1):
        res.append(i)
        solve(i, num+1)
        res.pop()


n, m = map(int, input().split())
res = []
solve(1, 0)
