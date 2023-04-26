class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 0, p = 0;
        string str;

        for (r = 1; r < chars.size(); r++)
        {
            if (chars[r] != chars[r - 1])
            {
                chars[p++] = chars[l];
                if (r - l > 1)
                {
                    str = to_string(r - l);
                    for (auto s : str)
                        chars[p++] = s;
                }

                l = r;
            }
        }

        chars[p++] = chars[l];
        if (r - l > 1)
        {
            for (auto s: to_string(r - l))
                chars[p++] = s;
        }

        return (p);
    }
};
