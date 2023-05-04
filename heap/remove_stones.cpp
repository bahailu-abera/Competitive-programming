class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());
        int total = accumulate(piles.begin(), piles.end(), 0);

        for (int i = 0; i < k; i++)
        {
            int current = pq.top();
            int remove = current / 2;
            pq.pop();
            pq.push(current - remove);
            total -= remove;
        }

        return total;
    }
};
