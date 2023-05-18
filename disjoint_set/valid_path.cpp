class UnionFind
{
public:
    UnionFind(int sz): parent(sz), Size(sz, 1)
    {
        for (int i = 0; i < sz; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        int root = x;

        while(parent[root] != root)
            root = parent[root];

        while(parent[x] != root)
        {
            int p = parent[x];
            parent[x] = root;
            x = p;
        }

        return root;
    }

    bool connected(int x, int y)
    {
        return Find(x) == Find(y);
    }

    void unionSet(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if (x == y)
            return;

        if (Size[x] < Size[y])
            std::swap(x, y);

        parent[y] = x;
        Size[x] += Size[y];
    }

private:
    vector<int> parent;
    vector<int> Size;
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
	int n = grid.size();
        int m = grid[0].size();

        UnionFind uf(n * m);

        function<bool(int, pair<int, int>)> comp = [&](int a, pair<int, int> current)
        {
            for (auto & d : directions[a])
            {
                if (d.first + current.first == 0 && d.second + current.second == 0)
                    return true;
            }

            return false;
        };

        for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
        {
            int c = grid[row][col];
            for (auto& d: directions[c])
            {
                int new_row = row + d.first;
                int new_col = col + d.second;

                if (new_row >= 0 && new_col >= 0 && new_row < n && new_col < m && comp(grid[new_row][new_col], d))
                {
                    uf.unionSet(row * m + col, new_row * m + new_col);
                }
            }
        }

        return uf.connected(0, n * m - 1);
    }

private:

unordered_map<int, vector<pair<int, int>>> directions = {
    {1, {{0, -1}, {0, 1}}},
    {2, {{-1, 0}, {1, 0}}},
    {3, {{0, -1}, {1, 0}}},
    {4, {{0, 1}, {1, 0}}},
    {5, {{0, -1}, {-1, 0}}},
    {6, {{-1, 0}, {0, 1}}}
};

};
