class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n + 1, -1);
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());

        for (auto edge: times)
            graph[edge[0]].push_back({edge[2], edge[1]});

        auto comp = [&](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

        distance[k] = 0;
        minHeap.push({0, k});

        while (!minHeap.empty())
        {
            auto current = minHeap.top();

            minHeap.pop();

            for (auto adj : graph[current.second])
            {
                int dist = current.first + adj.first;

                if (distance[adj.second] == -1 || distance[adj.second] > dist)
                {
                    distance[adj.second] = dist;
                    minHeap.push({dist, adj.second});
                }
            }
        }

        int delay = 0;

        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == -1)
                return -1;

            delay = max(delay, distance[i]);
        }

        return delay;
    }
};
