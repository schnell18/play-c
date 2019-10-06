/* compute the fibonacci series using iterative addition */
unsigned long fib(int n) {
    if (n == 0)
    {
        return 0;
    }
    unsigned long a = 1, b = 1, t = 0;
    for (int i = 3; i <= n; i++)
    {
        t = a;
        a = b;
        b = t + b;
    }
    return b;
}
