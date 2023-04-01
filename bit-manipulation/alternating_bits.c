bool hasAlternatingBits(int n){
    int bit = n & 1;
    n >>= 1;

    while (n)
    {
        if ((n & 1) ^ bit ^ 1)
            return (false);
        bit ^= 1;
        n >>= 1;
    }

    return (true);
}
