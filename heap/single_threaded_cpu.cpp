class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>order;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>inQueue;
        vector<array<int, 3>> sorted;

        for (int i = 0; i < tasks.size(); i++)
            sorted.push_back({tasks[i][0], tasks[i][1], i});

        sort(sorted.begin(), sorted.end());
        long long currentTime = 0;
        int index = 0;

        while (index < tasks.size() || !inQueue.empty())
        {
            if (inQueue.empty())
            {
                currentTime = sorted[index][0];
                while (index < sorted.size() && sorted[index][0] == currentTime)
                {
                    inQueue.push({sorted[index][1], sorted[index][2]});
                    index++;
                }
            }

            auto [processTime, idx] = inQueue.top();
            inQueue.pop();
            currentTime += processTime;
            order.push_back(idx);

            while (index < sorted.size() && sorted[index][0] <= currentTime)
            {
                inQueue.push({sorted[index][1], sorted[index][2]});
                index++;
            }
        }

        return order;
    }
};
