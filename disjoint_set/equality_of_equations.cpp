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
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);

        for (auto & s : equations)
        {
            if (s[1] == '=')
                uf.unionSet(s[0] - 'a', s[3] - 'a');
        }

        for (auto &s : equations)
        {
            if (s[1] == '!' && uf.connected(s[0] - 'a', s[3] - 'a'))
                return false;
        }

        return true;
    }
};
