
long long modexp(long long a, long long b , long long md) {
    assert(b >= 0);
    long long x = a, res = 1;
    long long p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
        res %= md;
        x %= md;
    }
    return res;
}
