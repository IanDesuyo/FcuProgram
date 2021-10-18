def Print_it_all(n: int):
    nums = []

    for i in range(n):
        if i % 7 != 0:
            nums.append(i)

    print(" ".join(map(str, nums)))


n = int(input())
Print_it_all(n)