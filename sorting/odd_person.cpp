#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
    bool parity[2] = {0, 0};
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        parity[arr[i] & 1] = 1;
    }

    if (parity[0] && parity[1])
        sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
        cout << arr[i] << " ";

    cout << arr[n - 1] << endl;

    delete []arr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    solve(n);

    return 0;
}
