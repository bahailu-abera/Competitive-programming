class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> ancestors(n);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        function<void(int, int)> dfs = [&](int vertex, int parent)
        {
            for (int adj: graph[vertex])
            {
                if (ancestors[adj].empty() || ancestors[adj].back() != parent)
                {
                    ancestors[adj].push_back(parent);
                    dfs(adj, parent);
                }
            }
        };

        for (int i = 0; i < n; i++)
        {
            dfs(i, i);
        }

        return ancestors;
    }
};
