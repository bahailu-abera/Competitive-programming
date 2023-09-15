class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = (int)s.size();
        vector<int> parent(n);
        vector<int> size(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x)
        {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        };

        function<void(int, int)> join = [&](int x, int y)
        {
            int px = find(x), py = find(y);

            if (px == py)
                return;

            if (size[px] < size[py])
                swap(px, py);

            parent[py] = px;

            size[px] += size[py];
        };

        for (auto edge: pairs)
            join(edge[0], edge[1]);

        vector<vector<int>> components(n);

        for (int i = 0; i < n; i++)
            components[find(i)].push_back(i);

        for (auto& component: components)
        {
            string temp;

            for (int idx: component)
                temp += s[idx];

            sort(temp.begin(), temp.end());

            for (int i = 0; i < (int)component.size(); i++)
                s[component[i]] = temp[i];
        }

        return s;
    }
};
