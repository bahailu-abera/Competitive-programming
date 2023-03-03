int mySqrt(int x){
    int low, high;
    int long mid;

    low = 1, high = x / 2;
    if (high < low) high = low;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid * mid == x)
            return (mid);
        if (mid * mid < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (low < high ? low : high);
}
