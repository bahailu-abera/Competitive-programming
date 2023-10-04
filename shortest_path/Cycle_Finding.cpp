#include <bits/stdc++.h>

using namespace std;

#define int long long



void solve()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> edges(m);
    vector<int> distance(n + 1, LONG_LONG_MAX);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        edges[i] = {a, b, c};
    }

    vector<int> parent(n + 1, -1);

    bool exist = false;

    for (int i = 1; i <= n; i++)
    {
        if (parent[i] != -1)
            continue;

        distance[i] = 0;
        parent[i] = i;

        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            if (!flag)
                break;
            
            flag = false;
            
            for (auto edge: edges)
            {
                if ((distance[edge[0]] != LONG_LONG_MAX) && (distance[edge[1]] > (distance[edge[0]] + edge[2])))
                {
                    distance[edge[1]] = distance[edge[0]] + edge[2];
                    parent[edge[1]] = edge[0];
                    flag = true;
                }
            }
        }

        int start = 0;

        for (auto edge: edges)
        {
            if ((distance[edge[0]] != LONG_LONG_MAX) && ((distance[edge[1]] > distance[edge[0]] + edge[2])))
            {
                start = edge[0];
                break;
            }
        }

        if (start == 0)
        {
            continue;
        }

        cout << "YES\n";

        for (int i = 1; i < n; i++)
        {    
            start = parent[start];
        }

        vector<int> cycle;

        cycle.push_back(start);

        int current = parent[start];

        while (current != start)
            cycle.push_back(current), current = parent[current];

        cycle.push_back(start);

        for (int i = (int)cycle.size() - 1; i >= 0; i--)
            cout << cycle[i] << " ";

        cout << "\n";

        exist = true;
        break;
    }

    if (!exist)
        cout << "NO\n";
}

#undef int

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
