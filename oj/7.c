unsigned long long power(unsigned long long base, unsigned long long exponent) {
    if (exponent == 0) {
        return 1;
    }

    return base * power(base, exponent - 1);
}
