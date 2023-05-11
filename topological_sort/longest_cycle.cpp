class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int max_cycle = -1;
        int time = 0;
        vector<int> visited(n);
        vector<int> start_time(n);

        function<void(int)> dfs = [&](int vertex)
        {
            if (edges[vertex] == -1) return; // dead end

            visited[vertex] = 1;
            start_time[vertex] = time;

            time++;
            if (!visited[edges[vertex]])
                dfs(edges[vertex]);

            else if (visited[edges[vertex]] == 1)
            {
                max_cycle = std::max(max_cycle, time - start_time[edges[vertex]]);
            }

            visited[vertex] = 2;
        };

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                time = 0;
                dfs(i);
            }
        }

        return max_cycle;
    }
};
