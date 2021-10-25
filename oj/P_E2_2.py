n = int(input())
x = []
y = []

for i in range(n):
    x.append(int(input()))

for i in range(n):
    y.append(int(input()))

print(len(set(x) & set(y)))
