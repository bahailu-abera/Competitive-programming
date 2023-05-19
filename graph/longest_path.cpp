class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        int longest_path = 0;

        for (int i = 1; i < n; i++)
        {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }

        function<int(int, int)> dfs = [&](int vertex, int parent)
        {
            int first_max = 0;
            int second_max = 0;

            for (int child : graph[vertex])
            {
                if (child != parent)
                {
                    int path_length = dfs(child, vertex);
                    if (s[vertex] == s[child])
                        longest_path = std::max(longest_path, path_length);

                    else
                    {
                        if (path_length > first_max)
                            second_max = first_max, first_max = path_length;

                        else if (path_length > second_max)
                            second_max = path_length;
                    }
                }
            }
            longest_path = std::max(first_max + second_max + 1, longest_path);

            return first_max + 1;
        };

        return std::max(dfs(0, -1), longest_path);
    }
};
