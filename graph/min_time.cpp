class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);

        for (auto & edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); // build the graph
        }

        function<pair<int, bool>(int, int)> dfs = [&](int current, int parent)
        {
            int times = 0;

            for (int child : graph[current])
            {
                if (child != parent)
                {
                   pair<int, bool> result = dfs(child, current);
                   times += result.first;
                   if (result.second || result.first) times += 2;
                }
            }

            return make_pair(times, hasApple[current]);
        };

        return dfs(0, -1).first;
    }
};
