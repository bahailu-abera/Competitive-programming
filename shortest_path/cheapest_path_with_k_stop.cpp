class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        vector<int> distance(n, -1);

        for (auto edge: flights)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        auto comp = [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];

            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        pq.push({0, 0, src});
        distance[src] = 0;


        while (!pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            int nodes = current[0], current_distance = current[1], curr = current[2];

            for (auto adj: graph[curr])
            {
                int new_distance = current_distance + adj.second;

                if ((distance[adj.first] == -1 || distance[adj.first] > new_distance) && nodes <= k)
                {
                    distance[adj.first] = new_distance;
                    pq.push({nodes + 1, new_distance, adj.first});
                }
            }
        }

        return distance[dst];
    }
};
