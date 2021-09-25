n = input()
p = list(map(int, input().split()))
p.sort()
print(p[0]*p[-1])
