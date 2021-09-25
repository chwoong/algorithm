import sys
input = sys.stdin.readline

length, n, rf, rb = map(int, input().split())
ans = 0
travel = 0
res = []
for i in range(n):
    x, c = map(int, input().split())
    res += [(c, x)]
res.sort(reverse=True)
for c, x in res:
    if travel < x:
        ans += (x - travel)*(rf-rb)*c
        travel = x
print(ans)


