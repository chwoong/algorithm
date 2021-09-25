import sys
input = sys.stdin.readline

dlong = []
ans = 0
for line in sys.stdin:
    x, y = map(int, line.split())
    dlong.append(x)
    ans += y*20
dlong.sort()
v = 0
for i in dlong:
    v += i
    ans += v
print(ans)
