#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++)
    {
        int src, dest, w;

        cin >> src >> dest >> w;

        edges[i] = {src - 1, dest - 1, w};
    }


    vector<int> distance(n, 3e4);


    bool flag = true;
    distance[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (!flag)
            break;

        flag = false;
        
        for (auto edge: edges)
        {
            if (distance[edge[0]] != 3e4 && distance[edge[1]] > distance[edge[0]] + edge[2])
                flag = true, distance[edge[1]] = distance[edge[0]] + edge[2];
        }
    }

    for (auto dis: distance)
        cout << dis << " ";

    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}