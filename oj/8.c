unsigned long long Fib(unsigned long long n) {
    if (n == 1) {
        return n;
    } else if (n < 1) {
        return 0;
    }

    return Fib(n - 1) + Fib(n - 2);
}