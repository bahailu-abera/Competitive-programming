class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void join(int x, int y)
    {
        int px = find(x), py = find(y);

        if (px == py)
            return;

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;

        size[px] += size[py];
    }

    bool isValid(string& a, string& b)
    {
        int match = 0;
        int n = (int)a.size();

        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                match++;
        }

        return match >= n - 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = (int)strs.size();
        size = vector<int>(n, 1);
        parent = vector<int>(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isValid(strs[i], strs[j]))
                    join(i, j);
            }
        }

        unordered_set<int> p;

        for (int i = 0; i < n; i++)
            p.insert(find(i));

        return (int)p.size();
    }
};
