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

    int source = edges[0][0];

    vector<int> parent(n + 1, source);

    distance[source] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto edge: edges)
        {

            if (distance[edge[0]] != LONG_LONG_MAX && distance[edge[1]] > distance[edge[0]] + edge[2])
            {
                distance[edge[1]] = distance[edge[0]] + edge[2];
                parent[edge[1]] = edge[0];
            }
        }
    }

    int start = 0;

    for (auto edge: edges)
    {
        if (distance[edge[0]] != LONG_LONG_MAX && distance[edge[0]] + edge[2] < distance[edge[1]])
        {
            start = edge[1];
            break;
        }

    }

    if (start == 0)
    {
        cout << "NO\n";
    }

    else
    {
        cout << "YES\n";

        for (int i = 0; i < n; i++)
            start = parent[start];

        vector<int> cycle;

        cycle.push_back(start);

        int current = parent[start];

        while (current != start)
            cycle.push_back(current), current = parent[current];

        cycle.push_back(start);

        for (int i = (int)cycle.size() - 1; i >= 0; i--)
            cout << cycle[i] << " ";

        cout << "\n";
    }
}


#undef int

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
