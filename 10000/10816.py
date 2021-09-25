import sys
from collections import defaultdict
# import bisect
input = sys.stdin.readline

n = int(input())
arr = defaultdict(int)
data = list(map(int, input().split()))
for i in data:
    arr[i] += 1
m = int(input())
brr = list(map(int, input().split()))
for i in brr:
    print(arr.get(i, 0), end=' ')
