import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
d = list(map(int, input().split()))
ans1 = -9876543210
ans2 = 9876543210


def solve(step, prev):
    if step == n:
        global ans1, ans2
        ans2 = min(ans2, prev)
        ans1 = max(ans1, prev)
    if d[0] > 0:
        d[0] -= 1
        solve(step+1, prev + arr[step])
        d[0] += 1
    if d[1] > 0:
        d[1] -= 1
        solve(step+1, prev - arr[step])
        d[1] += 1
    if d[2] > 0:
        d[2] -= 1
        solve(step+1, prev * arr[step])
        d[2] += 1
    if d[3] > 0:
        d[3] -= 1
        if prev >= 0:
            solve(step+1, prev // arr[step])
        else:
            solve(step+1, -(-prev // arr[step]))
        d[3] += 1


solve(1, arr[0])
print(ans1, ans2, sep='\n')
