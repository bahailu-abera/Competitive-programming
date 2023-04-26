class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemistry = 0;
        int left, right, current;

        sort(skill.begin(), skill.end());
        left = 0, right = skill.size() - 1;

        current = skill[left++] + skill[right--];
        chemistry += skill[left - 1] * skill[right + 1];

        while (left < right)
        {
            if (skill[left] + skill[right] != current)
                return (-1);

            chemistry += skill[left++] * skill[right--];
        }

        return chemistry;
    }
};
