def prime2(pStart: int = 2, pEnd: int = 20):
    primes = []
    for i in range(pStart, pEnd + 1):
        isPrime = True
        for j in range(2, i):
            if i % j == 0:
                isPrime = False
                break

        if isPrime:
            primes.append(i)

    print(" ".join(map(str, primes)))


m = int(input())
n = int(input())

prime2(m, n)
