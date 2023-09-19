class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> build_graph(vector<vector<string>>& equations, vector<double>& values)
    {
        int len = (int)equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < len; i++)
        {
            auto edge = equations[i];

            graph[edge[0]].push_back({edge[1], values[i]});

            if (values[i] != 0)
                graph[edge[1]].push_back({edge[0], 1L / values[i]});
        }

        return graph;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>> graph, unordered_set<string> visited, string start, string end)
    {
        if (start == end)
            return 1L;

        visited.insert(start);

        for (auto adj : graph[start])
        {
            if (!visited.count(adj.first))
            {
                double result = dfs(graph, visited, adj.first, end);

                if (result != -1)
                    return result * adj.second;
            }
        }

        return -1L;
    }

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int query_len = (int)queries.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        vector<double> result(query_len, -1.0L);

        graph = build_graph(equations, values);

        for (int i = 0; i < query_len; i++)
        {
            auto query = queries[i];

            if (!graph.count(query[0]) || !graph.count(query[1]))
                continue;

            result[i] = dfs(graph, unordered_set<string>(), query[0], query[1]);
        }

        return result;
    }
};
