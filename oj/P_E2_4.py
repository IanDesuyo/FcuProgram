import json

i = input()
data = json.loads(i)

q = ("Q1", "Q2")
ans = [0, 0]

for i in range(2):
    for name, status in data.get(q[i]).items():
        if "AC" in status:
            ans[i] += 1

for i in ans:
    print(i)