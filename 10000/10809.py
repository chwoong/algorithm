import sys
input = sys.stdin.readline

word = input()
for i in range(ord('a'), ord('z')+1):
    f = chr(i)
    print(word.find(f), end=' ')
