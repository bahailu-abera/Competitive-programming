class DisjointSet {
public:
    DisjointSet(int sz)
    {
        size = vector<int>(sz, 1);
        parent = vector<int>(sz);

        for (int i = 0; i < sz; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    void connect(int x, int y)
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

private:
    vector<int> parent;
    vector<int> size;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        int cost = 0;
       vector<vector<int>> edges;

        for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int cost = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
            edges.push_back({cost, i, j});
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(n);

        for (auto edge : edges)
        {
            if (!ds.isConnected(edge[1], edge[2]))
            {
                cost += edge[0];
                ds.connect(edge[1], edge[2]);
            }
        }

        return cost;
    }
};
