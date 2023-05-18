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


#define ALPH 26

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(ALPH);
        string equivalent = "";

        for (int i = 0; i < s1.size(); i++)
            uf.unionSet(s1[i] - 'a', s2[i] - 'a');

        for (char ch : baseStr)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (uf.connected(c - 'a', ch - 'a'))
                {
                    equivalent += c;
                    break;
                }
            }
        }

        return equivalent;
    }
};
