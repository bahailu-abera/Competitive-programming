class Solution {
public:
    vector<vector<int>> graph;
    vector<int> values;
    vector<long long> sum;
    int d;

    int dfs(int curr, int p = -1)
    {
        sum[curr] = values[curr];
        int count = 0;

        for (int adj : graph[curr])
        {
            if (adj != p)
            {
		    int child = dfs(adj, curr);

		    if (sum[adj] % d)
                {
                    sum[curr] += sum[adj];
                }

                count += child;
            }
        }

        return count + (sum[curr] % (long long)d == 0);
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& v, int k) {
        graph = vector<vector<int>>(n);
        sum = vector<long long>(n);
        d = k;
        values = v;

        for (auto edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(0);
    }
};
