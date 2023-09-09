class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = (int)satisfaction.size();
        int sum = 0, maxValue = 0;

        sort(satisfaction.begin(), satisfaction.end());

        for (int i = n - 1; i >= 0; i--)
        {
            int current = maxValue + sum + satisfaction[i];

            if (current < maxValue)
                return maxValue;

            sum += satisfaction[i];
            maxValue = current;
        }

        return maxValue;
    }
};
