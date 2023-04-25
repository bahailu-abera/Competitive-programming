#include <bits/stdc++.h>

using namespace std;

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

string solve(int n)
{
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    qsort(arr, n, sizeof(int), cmp);

    for (int i = 1; i < n; i++)
        if ((arr[i] - arr[i - 1]) > 1)
            return "NO\n";

    delete[] arr;

    return "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, testcase;
    cin >> testcase;

    while (testcase--)
    {
        cin >> n;
        cout << solve(n);
    }

    return 0;
}
