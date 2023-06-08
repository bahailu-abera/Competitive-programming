class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            int l = i - 1, r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r])
                --l, ++r;

            if (maxLength < (r - l - 1))
                maxLength = r - l - 1, start = l + 1;

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
                --l, ++r;

            if (maxLength < (r - l - 1))
                maxLength = r - l - 1, start = l + 1;
        }

        return s.substr(start, maxLength);
    }
};
