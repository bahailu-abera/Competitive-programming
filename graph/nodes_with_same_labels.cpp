class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        vector<int> same_labels(n);

        for (auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        function<vector<int>(int, int)> dfs = [&](int current, int parent)
        {
            vector<int> freq(26);

            for (int child : graph[current])
                if (child != parent)
                {
                    vector<int> childFreq = dfs(child, current);
                    std::transform (freq.begin(), freq.end(), childFreq.begin(), freq.begin(), std::plus<int>());
                }

            freq[labels[current] - 'a']++;

            same_labels[current] = freq[labels[current] - 'a'];

            return freq;
        };

        dfs(0, -1);

        return same_labels;
    }
};
