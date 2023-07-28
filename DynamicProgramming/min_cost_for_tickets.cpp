/**
Solution 1 : recursive based dp solution.
 **/
class Solution {
public:
    vector<int> memo;

    Solution() : memo(366, -1) {}

    int dp(int current, vector<int>& days, vector<int>& costs)
    {
        if (current <= 0)
        {
            return (0);
        }

        if (memo[current] != -1)
            return memo[current];

        int day = dp(current - 1, days, costs) + costs[0] * days[current];
        int week = dp(current - 7, days, costs) + costs[1];
        int month = dp(current - 30, days, costs) + costs[2];

        return memo[current] = std::min(day, std::min(week, month));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int const sz = 366;
        int const len = (int)days.size();

        vector<int> temp(sz, 0);

        for (int day : days)
            temp[day] = 1;

        return dp(days[len - 1], temp, costs);
    }
};
