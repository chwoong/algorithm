import sys
# import bisect
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
m = int(input())
brr = list(map(int, input().split()))
arr.sort()
for x in brr:
    # x �̻��� ù��° ������ ��ġ�� ��ȯ�� ���̴�.
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
