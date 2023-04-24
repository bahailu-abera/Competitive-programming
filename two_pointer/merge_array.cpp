#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m)
{
    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int l = 0, r = 0;
    for (; l < n && r < m; )
    {
        if (arr1[l] <= arr2[r])
            cout << arr1[l++] << " ";

        else
            cout << arr2[r++] << " ";
    }

    for (; l < n; l++)
    {
        cout << arr1[l];
        if (l != n - 1)
            cout << " ";
    }

    for (; r < m; r++)
    {
        cout << arr2[r];
        if (r != m - 1)
            cout << " ";
    }
}

int main(void)
{
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    solve(n, m);

    return (0);
}
