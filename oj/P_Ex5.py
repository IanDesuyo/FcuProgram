n = list(map(int, input().split()))

if n[3] - n[2] == n[2] - n[1]:
    n.append(n[3] * 2 - n[2])
else:
    n.append(int(n[3] * (n[2] / n[1])))

print(n[-1])