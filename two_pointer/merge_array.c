void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    int *array = malloc(sizeof(int) * nums1Size);
    int i, j, k;

    for (i=j=k=0; i < m && j < n;)
    {
        if (nums1[i] < nums2[j])
            array[k] = nums1[i], i++;
        else
            array[k] = nums2[j], j++;
        k++;
    }
    while (i < m)
        array[k] = nums1[i], i++, k++;
    while (j < n)
        array[k] = nums2[j], j++, k++;
    for (i = 0; i < nums1Size; i++)
        nums1[i] = array[i];
}
