def isLeap(year: int):
    leap = False
    if year % 4 == 0:
        leap = True
    if year % 100 == 0 and year % 100 != 0:
        leap = True
    if year % 100 == 0 and year % 400 != 0:
        leap = False
    if year % 400 == 0:
        leap = True
    return leap


a = int(input())
b = int(input())
ans = 0

for i in range(a, b + 1):
    if isLeap(i):
        ans += 1

print(ans)