class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> distance(n, 0.0);

        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());

        for (int i = 0; i < (int)edges.size(); i++)
        {
            auto edge = edges[i];
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;

        distance[start] = 1;

        pq.push({1, start});

        while (!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto edge: graph[node])
            {
                double newProb = prob * edge.second;

                if (newProb > distance[edge.first])
                {
                    distance[edge.first] = newProb;

                    pq.push({newProb, edge.first});
                }
            }
        }

        return distance[end];
    }
};
