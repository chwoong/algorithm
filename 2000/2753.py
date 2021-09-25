a = int(input())
# ¿±≥‚¿Ã∏È 0
b = 0
if a % 400 == 0:
    b = 1
elif a % 100 == 0:
    b = 0
elif a % 4 == 0:
    b = 1
print(b)
