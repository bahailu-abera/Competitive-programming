class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int s: stones) pq.push(s);

        while (!pq.empty())
        {
            int first = pq.top();
            pq.pop();

            if (pq.empty()) return first;
            int second = pq.top();
            pq.pop();

            if (first < second) pq.push(second - first);

            else if (first > second) pq.push(first - second);
        }

        return (0);
    }
};
