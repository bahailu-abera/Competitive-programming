class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n);
        vector<int> safeNodes;

        function<bool(int)> dfs = [&](int vertex)
        {
            visited[vertex] = 1;
            for (int adj : graph[vertex])
            {
                if (visited[adj] != 2)
                {
                    if (visited[adj] == 1)
                        return false; // cycle detected

                    if (!dfs(adj)) return false;
                }
            }

            visited[vertex] = 2;

            return true;
        };

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && dfs(i))
                safeNodes.push_back(i);

            else if (visited[i] == 2)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
