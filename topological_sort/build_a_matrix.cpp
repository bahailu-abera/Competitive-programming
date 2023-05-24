class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> mat(k, vector<int>(k, 0));
        vector<vector<int>> row_graph(k + 1);
        vector<vector<int>> col_graph(k + 1);
        vector<int> indegree(k + 1);

        for (auto edge : rowConditions)
        {
            row_graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> Q;
        for (int i = 1; i <= k; i++)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }

        unordered_map<int, int> row;
        int r = 0;
        while (!Q.empty())
        {
            int current = Q.front();
            row[current] = r++;

            Q.pop();

            for (int adj : row_graph[current])
                if (--indegree[adj] == 0)
                    Q.push(adj);
        }

        if (row.size() != k)
            return vector<vector<int>> ();

        vector<int> indeg(k + 1);

        for (auto edge : colConditions)
        {
            col_graph[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        for (int i = 1; i <= k; i++)
        {
            if (indeg[i] == 0)
                Q.push(i);
        }

        unordered_map<int, int> col;
        int c = 0;
        while (!Q.empty())
        {
            int current = Q.front();
            col[current] = c++;

            Q.pop();

            for (int adj : col_graph[current])
                if (--indeg[adj] == 0)
                    Q.push(adj);
        }

        if (col.size() != k)
            return vector<vector<int>> ();

        for (int i = 1; i <= k; i++)
        {
            int r = row[i];
            int c = col[i];

            mat[r][c] = i;
        }

        return mat;
    }
};
