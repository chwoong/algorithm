import sys
input = sys.stdin.readline

n = int(input())
arr = []
num = [0, 0]
for i in range(n):
    x = list(map(int, input().split()))
    arr.append(x)


def solve(i, j, size):
    if size == 1:
        num[arr[i][j]] += 1
        return
    chk = True
    for ii in range(i, i+size):
        for jj in range(j, j+size):
            if arr[ii][jj] != arr[i][j]:
                chk = False
                break
    # 모두 같은 색
    if chk:
        num[arr[i][j]] += 1
    else:
        solve(i, j, size//2)
        solve(i+size//2, j, size//2)
        solve(i, j+size//2, size//2)
        solve(i+size//2, j+size//2, size//2)


solve(0, 0, n)
print(num[0])
print(num[1])
