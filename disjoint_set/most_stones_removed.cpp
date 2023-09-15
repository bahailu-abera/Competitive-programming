class DisjointSet {
public:
    DisjointSet(int sz)
    {
        n = sz;
        parent = vector<int>(n);
        size = vector<int>(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;

        size[px] += size[py];
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    int sz(int x)
    {
        int px = find(x);

        int s = size[px];

        size[px] = 1;

        return s;
    }

private:
    int n;
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = (int)stones.size();
        int removed = 0;
        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    ds.merge(i, j);
            }
        }

        for (int i = 0; i < n; i++)
        {
            removed += ds.sz(i) - 1;
        }

        return removed;
    }
};
