#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
    long long sum = 0;
    int negative = 0, positive = 0;

    for (int i = 0; i < n; i++)
    {
        int current;
        cin >> current;

        if ((current < 0) && (negative == 0 || current > negative))
            sum += positive, positive = 0, negative = current;

        else if ((current > 0) && (positive == 0 || positive < current))
            sum += negative, negative = 0, positive = current;
    }

    sum += negative;
    sum += positive;

    cout << sum << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase, n;

    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        solve(n);
    }

    return (0);
}
