int hIndex(int* citations, int citationsSize){
    int low, mid, high;

    low = 0, high = citationsSize - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (citationsSize - mid <= citations[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (citationsSize - low);
}
