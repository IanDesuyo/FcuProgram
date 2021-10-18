myList = []
n = int(input())

for i in range(n):
    num = int(input())
    myList.append(num)

myList.sort(reverse=True)

for i in range(n):
    print(myList[i])