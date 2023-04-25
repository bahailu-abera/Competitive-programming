#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m)
{
    map<tuple<int, int>, int> repeated;
    vector<vector<char>> table(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        map<char, int> hash;
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            hash[c] = hash[c] + 1;

            table[i][j] = c;
        }

        for (int j = 0; j < m; j++)
        {
            if (hash[table[i][j]] > 1)
            {
                tuple<int, int> t(i, j);
                repeated[t] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        map<char, int> hash;

        for (int j = 0; j < n; j++)
        {
            char c = table[j][i];

            hash[c] = hash[c] + 1;
        }

        for (int j = 0; j < n; j++)
        {
            char c = table[j][i];
            if (hash[c] > 1)
            {
                tuple<int, int> t(j, i);
                repeated[t] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tuple<int, int> t(i, j);
            if (repeated[t] == 0)
                cout << table[i][j];
        }
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    solve(n, m);

    return 0;
}
