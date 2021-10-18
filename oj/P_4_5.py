myList = []
n = int(input())

for i in range(n):
    num = int(input())
    myList.append(num)

print(sum(myList))
print(len(myList))
print("%.2f" % (sum(myList) / len(myList)))
