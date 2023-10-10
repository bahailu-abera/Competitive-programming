class Solution {
public:
    int dfs(int current, int halfed, int parent, vector<int>& freq)
    {
        int fullCost = prices[current] * freq[current];
        int halfCost = fullCost / 2;

        if (memo[current][halfed] != -1)
            return memo[current][halfed];

        for (auto adj : graph[current])
        {
            if (adj != parent)
                fullCost += dfs(adj, 0, current, freq);
        }

        if (halfed)
        {
            return memo[current][halfed] = fullCost;
        }

        for (auto adj: graph[current])
        {
            if (adj != parent)
            {
                halfCost += dfs(adj, 1, current, freq);
            }
        }

        return memo[current][halfed] = min(fullCost, halfCost);
    }

    bool findFreq(int current, int parent, int target, vector<int>& freq)
    {
        freq[current]++;

        if (current == target)
            return true;

        for (auto adj: graph[current])
        {
            if (adj != parent)
            {
                if (findFreq(adj, current, target, freq))
                {
                    return true;
                }
            }
        }

        freq[current]--;

        return false;
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
			  vector<vector<int>>& trips) {
        vector<int> freq(n, 0);
        graph = vector<vector<int>>(n, vector<int>());
        prices = price;

        for (auto edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (auto trip: trips)
        {
            findFreq(trip[0], -1, trip[1], freq);
        }

        memo = vector<vector<int>>(n, vector<int>(2, -1));

        return dfs(0, 0, -1, freq);
    }

private:
    vector<vector<int>> graph;
    vector<int> prices;
    vector<vector<int>> memo;
};
