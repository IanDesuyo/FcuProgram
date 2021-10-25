gender = input()
age = int(input())

if gender == "F":
    if age >= 19:
        print("woman")
    elif age >= 13:
        print("girl")
    else:
        print("little girl")
else:
    if age >= 19:
        print("man")
    elif age >= 13:
        print("boy")
    else:
        print("little boy")