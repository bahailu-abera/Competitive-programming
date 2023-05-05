class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;


        for (int n: nums)
        {
            if (m.find(n - 1) == m.end() || m[n - 1].empty())
            {
                m[n].push(1);
            }

            else
            {
                int min_len = m[n - 1].top();
                m[n].push(min_len + 1);
                m[n - 1].pop();
            }
        }

        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (!(it->second).empty() && (it->second).top() < 3)
                return false;
        }

        return true;
    }
};
