import sys
input = sys.stdin.readline

n = int(input())
arr = []
sumarr = 0
for i in range(n):
    k = list(map(int, input().split()))
    sumarr += sum(k)
    arr.append(k)

team1 = []
team2 = []
minans = 1000000000


def solve(chk):
    if len(team1) > n // 2:
        return
    if chk == n:
        if len(team1) == n // 2:
            val = 0
            for i in team1:
                for j in team1:
                    val += arr[i][j]
            for i in team2:
                for j in team2:
                    val -= arr[i][j]
            val = abs(val)
            global minans
            minans = min(minans, val)
            return
        else:
            return
    else:
        team1.append(chk)
        solve(chk+1)
        team1.pop()
        team2.append(chk)
        solve(chk+1)
        team2.pop()


solve(0)
print(minans)
