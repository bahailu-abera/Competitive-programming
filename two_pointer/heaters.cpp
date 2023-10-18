class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int radius = 0;
        int left = 0, n = (int)heaters.size();

        for (int i = 0; i < (int)houses.size(); i++)
        {
            while (left + 1 < n && abs(heaters[left] - houses[i]) >= abs(heaters[left + 1] - houses[i]))
                left++;

            radius = max(radius, abs(heaters[left] - houses[i]));
        }

        return radius;
    }
};
