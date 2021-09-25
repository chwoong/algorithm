import sys
input = sys.stdin.readline

matrixa = []
matrixb = []
an, am = map(int, input().split())
for i in range(an):
    row = list(map(int, input().split()))
    matrixa.append(row)

bm, bk = map(int, input().split())
for i in range(bm):
    row = list(map(int, input().split()))
    matrixb.append(row)

ans = [[0 for col in range(bk)] for row in range(an)]
for i in range(an):
    for j in range(bk):
        for x in range(am):
            ans[i][j] += matrixa[i][x]*matrixb[x][j]
for i in range(an):
    print(*(ans[i]))
