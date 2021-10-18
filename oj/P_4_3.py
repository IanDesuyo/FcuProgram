myList = []
n = int(input())

for i in range(n):
    myList.append(input())

s = int(input())
j = int(input())
for i in range(s, j + 1):
    print(myList[i])