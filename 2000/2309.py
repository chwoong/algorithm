import sys
arr = []
s = 0
for i in range(9):
    arr.append(int(input()))
    s += arr[i]
arr.sort()
for i in range(9):
    for j in range(9):
        if (i != j) and (s == 100 + arr[i] + arr[j]):
            a = arr[i]
            b = arr[j]
            arr.remove(a)
            arr.remove(b)
            print(*arr, sep='\n')
            sys.exit()
