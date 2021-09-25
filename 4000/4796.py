import sys
input = sys.stdin.readline

cnt = 1
while 1:
    ll, p, v = map(int, input().split())
    if ll == 0:
        break
    m = v // p
    ans = m * ll
    ans += min(v - m * p, ll)
    print('Case ', cnt, ': ', ans, sep='')
    cnt += 1