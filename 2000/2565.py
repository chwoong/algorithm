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
# ret ���� ���� �� ���������� ���̸� ã��
dp = [ret[0]]
for i in range(1, num):
    if dp[-1] < ret[i]:
        dp.append(ret[i])
    else:
        k = bisect.bisect_left(dp, ret[i])
        dp[k] = ret[i]
print(num-len(dp))
