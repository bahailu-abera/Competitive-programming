class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        vector<int> array;

        for (auto &edge : adjacentPairs)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> Q;

        for (auto [num, edges]: graph)
        {
            if (edges.size() == 1)
            {
                Q.push(num);
                break;
            }
        }

        while (!Q.empty())
        {
            int current = Q.front();
            array.push_back(current);
            Q.pop();

            for (int adj: graph[current])
            {
                if (!graph[adj].empty())
                    Q.push(adj);
            }
            graph[current] = {};
        }

        return array;
    }
};
