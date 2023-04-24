#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m)
{
    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    // vector<int> count(m, 0);
    int l = 0;
    for (int r = 0; r < m; r++)
    {
        while (l < n && arr1[l] < arr2[r])
            l++;

        // count[r] = l;
        cout << l;
        if (r != m - 1)
            cout << " ";
    }

    cout << endl;
}

int main(void)
{
    int n, m;

    cin >> n >> m;

    solve(n, m);

    return (0);
}
