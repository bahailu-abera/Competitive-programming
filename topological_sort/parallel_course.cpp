#include <bits/stdc++.h>

int parallelCourses(int n, vector<vector<int>> &prerequisites)
{
    // Write your code here.
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(n + 1);

    for (auto &edge : prerequisites)
    {
        graph[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<pair<int, int>> Q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            Q.push(make_pair(i, 1));
    }

    int sem = 1;
    while (!Q.empty())
    {
        pair<int, int> current = Q.front();
        int node = current.first;
        sem = current.second;
        Q.pop();

        for (int adj: graph[node])
        {
            if (--indegree[adj] == 0)
            {
                Q.push(make_pair(adj, sem + 1));
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] != 0)
            return -1;
    }

    return sem;
}
