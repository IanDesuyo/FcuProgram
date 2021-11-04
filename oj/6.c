unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}