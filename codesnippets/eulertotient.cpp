long long totient(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result = result / p * (p - 1);
            do {
                n /= p;
            } while (n % p == 0);
        }
 
    if (n > 1)
        result = result / n * (n - 1);
 
    return result;
}
