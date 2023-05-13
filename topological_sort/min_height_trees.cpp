class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        deque<int> Q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] <= 1)
                Q.push_back(i);
        }

        while (!Q.empty() && n > 2)
        {
            int leaves = Q.size();
            n -= leaves;
            for (int i = 0; i < leaves; i++)
            {
                int current = Q.front();
                Q.pop_front();

                for (int adj : graph[current])
                {
                    if (--indegree[adj] == 1)
                        Q.push_back(adj);
                }
            }
        }

        vector<int> ans(Q.begin(), Q.end());

        return ans;
    }
};
