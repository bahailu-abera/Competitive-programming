class Solution {
public:
    bool isInside(vector<int> circle, vector<int> point)
    {
        long long x = (long long)circle[0], y = (long long)circle[1], r2 = (long long)circle[2] * (long long)circle[2];
        return (x - point[0]) * (x - point[0]) + (y - point[1]) * (y - point[1]) <= r2;
    }

    int dfs(vector<vector<int>>& graph, int current, vector<int>& visited)
    {
        int count = 0;
        visited[current] = 1;

        for (int n : graph[current])
        {
            if (visited[n] == 0)
            {
                count += dfs(graph, n, visited);
            }
        }

        return count + 1;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int length = int(bombs.size());
        if (length == 0) return 0;
        int detonated = 0;
        vector<vector<int>> graph(length, vector<int>());

        for (int i = 0; i < length; i++)
        {
            vector<int> circle{bombs[i][0], bombs[i][1], bombs[i][2]};
            for (int j = 0; j < length; j++)
            {
                vector<int> point{bombs[j][0], bombs[j][1]};
                if (isInside(circle, point))
                {
                    graph[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < length; i++)
        {
            vector<int> visited(length, 0);
            int current = dfs(graph, i, visited);

            if (current > detonated) detonated = current;
        }

        return detonated;
    }
};
