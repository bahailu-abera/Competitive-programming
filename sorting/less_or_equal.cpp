#include <bits/stdc++.h>

using namespace std;

#define x 1000000000

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int solve(int n, int k)
{
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    qsort(arr, n, sizeof(int), cmp);

    if (n == k)
        return (x);

    if (k == 0 && arr[0] == 1)
        return -1;

    if (k == 0 && arr[0] > 1)
        return 1;

    if (arr[k - 1] != arr[k])
        return arr[k - 1];

    return (-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    cout << solve(n, k);

    return 0;
}
