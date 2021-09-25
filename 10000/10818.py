n = int(input())
arr = map(int, input().split())
arr = list(arr)
arr.sort()

print(arr[0], arr[-1])
