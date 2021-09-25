import sys
import bisect
input = sys.stdin.readline

num = int(input())
pos = [0] * 1000
for i in range(num):
    a, b = map(int, input().split())
    pos[a] = b
ret = []
for i in pos:
    if i != 0:
        ret.append(i)
# ret 에서 가장 긴 증가수열의 길이를 찾자
dp = [ret[0]]
for i in range(1, num):
    if dp[-1] < ret[i]:
        dp.append(ret[i])
    else:
        k = bisect.bisect_left(dp, ret[i])
        dp[k] = ret[i]
print(num-len(dp))
