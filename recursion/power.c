double _pow(double x, int n)
{
    if (n == 0)
        return 1;
    double half = _pow(x, n / 2);
    if ((n & 1) == 0)
        return half * half;
    else
        return half * half * x;
}

double myPow(double x, int n)
{
    if (n >= 0)
        return (_pow(x, n));
    if (n == INT_MIN)
        return (1 / (x * _pow(x, -(n + 1))));
    return (1 / _pow(x, -n));
}
