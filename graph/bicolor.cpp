#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>>& graph, int vertex)
{
    int nodes = int(graph.size());
    vector<int>colors(nodes + 1, -1);
    queue<int> Q;

    int color = 0;
    colors[vertex] = color;
    Q.push(vertex);

    while (!Q.empty())
    {
        int level = Q.size();

        for (int i = 0; i < level; i++)
        {
            int current = Q.front();
            Q.pop();

            for (int adj: graph[current])
            {
                if (colors[adj] == -1)
                {
                    colors[adj] = color ^ 1;
                    Q.push(adj);

                }
                else if (colors[adj] == color) return false;
            }
        }

        color ^= 1;
    }

    return true;
}

void solve(int nodes, int edges)
{
    int src, dest;
    vector<vector<int>> graph(nodes + 1, vector<int>());

    for (int i = 0; i < edges; i++)
    {
        cin >> src >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    if (bfs(graph, 1))
        cout << "BICOLOURABLE.\n";
    else
        cout << "NOT BICOLOURABLE.\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, edges;

    while (true)
    {
        cin >> nodes;
        if (nodes == 0)
            return (0);
        cin >> edges;
        solve(nodes, edges);
    }
}
