import sys
input = sys.stdin.readline

testcase = int(input())
ret = [0] * 110
ret[0] = ret[1] = ret[2] = 1


def solve(n):
    if n == 0 or n == 1 or n == 2:
        return ret[n]
    if ret[n] != 0:
        return ret[n]
    else:
        ret[n] = solve(n-2) + solve(n-3)
        return ret[n]


for i in range(testcase):
    print(solve(int(input())-1))
