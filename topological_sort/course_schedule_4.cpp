class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        unordered_map<int, unordered_set<int>> prereq;

        for (auto& edge : prerequisites)
        {
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
        }

        queue<int> Q;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                Q.push(i);

        while (!Q.empty())
        {
            int current = Q.front();
            Q.pop();

            for (int adj : graph[current])
            {
                prereq[adj].insert(current);
                prereq[adj].insert(prereq[current].begin(), prereq[current].end());
                if (--indegree[adj] == 0)
                    Q.push(adj);
            }
        }

        vector<bool> answer(queries.size());

        int i = 0;
        for (auto &q: queries)
        {
            if (prereq[q[1]].count(q[0]))
                answer[i++] = true;

            else
                answer[i++] = false;
        }

        return answer;
    }
};
