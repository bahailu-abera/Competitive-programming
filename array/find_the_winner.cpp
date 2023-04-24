class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> d;

        for (int i = 0; i < n; i++)
            d.push_back(n - i);

        while (d.size() > 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                d.push_front(d.back());
                d.pop_back();
            }
            d.pop_back();
        }
        return d.back();
    }
};
