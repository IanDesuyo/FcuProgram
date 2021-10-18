scores = [0, 0, 0]

for i in range(4):
    studentScore = list(map(int, input().split()))

    for j in range(3):
        scores[j] += studentScore[j]

for score in scores:
    print(score)