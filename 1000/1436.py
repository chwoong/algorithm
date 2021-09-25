def check(i):
    length = len(str(i))
    for x in range(0, length-2):
        if str(i)[x] == '6' and str(i)[x+1] == '6' and str(i)[x+2] == '6':
            return 1
    return 0


n = int(input())
i = 665
while n != 0:
    i += 1
    if check(i):
        n -= 1

print(i)
