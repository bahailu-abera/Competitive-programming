int bit_count(int n)
{
    int count = 0;

    while (n)
        count += n & 1, n >>= 1;

    return (count);
}

int hammingDistance(int x, int y){
    return (bit_count(x ^ y));
}
