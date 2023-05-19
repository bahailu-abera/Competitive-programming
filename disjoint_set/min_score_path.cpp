class UnionFind
{
public:
    UnionFind(int sz): parent(sz + 1), Size(sz + 1, 1), Min(sz + 1)
    {
        for (int i = 1; i <= sz; i++)
        {
            parent[i] = i;
            Min[i] = INT_MAX;
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

    void unionSet(int x, int y, int distance)
    {
        x = Find(x);
        y = Find(y);

        Min[x] = std::min(Min[x], Min[y]);
        Min[x] = std::min(Min[x], distance);

        if (x == y)
            return;

        if (Size[x] < Size[y])
            std::swap(x, y);

        parent[y] = x;

        Size[x] += Size[y];
        Min[x] = std::min(Min[x], Min[y]);
        Min[x] = std::min(Min[x], distance);

    }

    int getMin(int x)
    {
        x = Find(x);

        return Min[x];
    }

private:
    vector<int> parent;
    vector<int> Size;
    vector<int> Min;
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind uf(n);

        for (auto &road : roads)
        {
            uf.unionSet(road[0], road[1], road[2]);
        }

        return uf.getMin(n);
    }
};
