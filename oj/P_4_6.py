myList = []
n = int(input())

for i in range(n):
    num = int(input())
    myList.append(num)

print(max(myList))
print(min(myList))