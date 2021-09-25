import sys
# import bisect
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
m = int(input())
brr = list(map(int, input().split()))
arr.sort()
for x in brr:
    # x 이상의 첫번째 원소의 위치를 반환할 것이다.
    l0 = -1
    hi = n - 1
    while(l0 + 1 < hi):
        mid = (l0 + hi) // 2
        if arr[mid] < x:
            l0 = mid
        else:
            hi = mid
    if arr[hi] == x:
        print(1)
    else:
        print(0)
