class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        vector<int> answer(n);

        for (auto & edge: richer)
        {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        for (int i = 0; i < n; i++) answer[i] = i;

        queue<int> Q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }

        while (!Q.empty())
        {
            int current = Q.front();
            Q.pop();

            for (int adj : graph[current])
            {
                if (quiet[answer[current]] < quiet[answer[adj]])
                    answer[adj] = answer[current];

                if (--indegree[adj] == 0)
                    Q.push(adj);
            }
        }

        return answer;
    }
};
