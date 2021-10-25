year = int(input())
leap = False

if year % 4 == 0:
    leap = True
if year % 100 == 0 and year % 100 != 0:
    leap = True
if year % 100 == 0 and year % 400 != 0:
    leap = False
if year % 400 == 0:
    leap = True

print("LeapYear" if leap else "NormalYear")