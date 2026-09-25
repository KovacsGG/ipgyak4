long long fib(int n) {
    if (n <= 1) return n;
    //return fib(n - 1) + fib(n - 2);
    long long a, b, c;
    a = 1;
    b = 1;
    for (int i = 2; i < n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}