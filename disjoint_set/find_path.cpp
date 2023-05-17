class UnionFind
{
public:
    UnionFind(int sz): parent(sz + 1), Size(sz + 1, 1)
    {
        for (int i = 1; i <= sz; i++)
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
        if (x == y)
            return true;
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);

        for (auto &edge: edges)
        {
            uf.unionSet(edge[0], edge[1]);
        }

        return uf.connected(source, destination);
    }
};
