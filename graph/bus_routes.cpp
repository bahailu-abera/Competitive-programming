class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int buses = routes.size();
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visitedStation;
        vector<int> visitedBuses(buses, 0);
        int usedBus = 0;

        for (int i = 0; i < buses; i++)
        {
            for (int station : routes[i])
                graph[station].push_back(i);
        }

        queue<int> Q;
        Q.push(source);
        visitedStation.insert(source);

        while (!Q.empty())
        {
            int level = (int)Q.size();

            for (int i = 0; i < level; i++)
            {
                int current = Q.front();
                Q.pop();

                if (current == target)
                    return usedBus;

                for (int bus : graph[current])
                {
                    if (!visitedBuses[bus])
                    {
                        visitedBuses[bus] = 1;
                        for (int station: routes[bus])
                        {
                            if (!visitedStation.count(station))
                                Q.push(station), visitedStation.insert(station);
                        }
                    }
                }
            }
            usedBus++;
        }

        return -1;
    }
};
