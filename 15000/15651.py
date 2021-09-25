def solve(num):
    if num == m:
        print(*res)
        return
    for i in range(1, n+1):
        res.append(i)
        solve(num+1)
        res.pop()
    

n ,m = map(int,input().split())
res = []
solve(0)