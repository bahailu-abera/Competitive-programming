class Solution {
public:
    bool isBeautiful(vector<int>& nums)
    {
        int n = (int)nums.size();

        for (int i = 1; i <= n; i++)
        {
            if (0 != nums[i - 1] % i && 0 != i % nums[i - 1])
                return false;
        }

        return true;
    }

    void backtrack(vector<int>& chosen, int used, int n)
    {
        int len = (int)chosen.size();

        if (!isBeautiful(chosen) || len > n)
        {
            return;
        }

        if (len == n)
        {
            total++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            int mask = (used >> i) & 1;

            if (mask)
                continue;// the element is already in the chosen list.

            used |= (1 << i);
            chosen.push_back(i + 1);

            backtrack(chosen, used, n);

            chosen.pop_back();
            used ^= (1 << i);
        }
    }

    int countArrangement(int n) {
        vector<int> chosen;

        backtrack(chosen, 0, n);

        return total;
    }
private:
    int total = 0;
};
