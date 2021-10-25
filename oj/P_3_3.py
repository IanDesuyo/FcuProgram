score = int(input())

if score >= 60:
    print("pass")
    if score >= 90:
        print("excellent")
elif score >= 50:
    print("almost pass")
else:
    print("fail")
