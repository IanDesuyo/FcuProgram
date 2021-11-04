unsigned long long cache[1000] = {1};

unsigned long long calc(unsigned long long n) {
    if (cache[n] != 0) {
        return cache[n];
    }

    cache[n] = n * calc(n - 1);
    return cache[n];
}