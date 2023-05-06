class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 1; i < heights.size(); i++)
        {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0) continue;

            if (ladders > 0)
            {
                minHeap.push(diff);
                ladders--;
            }

            else
            {
                if (!minHeap.empty() && diff > minHeap.top() && minHeap.top() <= bricks)
                {
                    bricks -= minHeap.top();
                    minHeap.pop();
                    minHeap.push(diff);
                }

                else if (diff <= bricks)
                    bricks -= diff;

                else
                    return (i - 1);
            }
        }

        return heights.size() - 1;
    }
};
