/**
Topological sorting solution.
**/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n, 0);

        for (auto edge: prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> Q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }

        while (!Q.empty())
        {
            auto current = Q.front();
            Q.pop();

            for (auto adj: graph[current])
            {
                if (--indegree[adj] == 0)
                {
                    Q.push(adj);
                }

                memo[current][adj] = true;

                for (int i = 0; i < n; i++)
                {
                    if (memo[i][current])
                        memo[i][adj] = true;
                }

                memo[current][adj] = true;
            }
        }

        vector<bool> result((int)queries.size(), false);

        for (int i = 0; i < (int)queries.size(); i++)
        {
            result[i] = memo[queries[i][0]][queries[i][1]];
        }

        return result;
    }
};

/**
Floyd-Warshall
**/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int q = (int)queries.size();
        vector<vector<bool>> distance(n, vector<bool>(n, false));

        for (auto edge: prerequisites)
        {
            distance[edge[0]][edge[1]] = true;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (distance[i][k] && distance[k][j])
                        distance[i][j] = true;
                }
            }
        }

        vector<bool> result(q);

        for (int i = 0; i < q; i++)
            result[i] = distance[queries[i][0]][queries[i][1]];

        return result;
    }
};
