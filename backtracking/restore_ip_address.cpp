class Solution {
public:
    void backtrack(vector<int>& chosen, string s, int index)
    {
        int n = (int)chosen.size();

        if (index >= (int)s.size() && n == 4)
        {
            string ip = "";

            for (int n : chosen)
                ip += to_string(n), ip += '.';

            ip.pop_back();

            result.push_back(ip);

            return;
        }

        if (index >= (int)s.size() || n > 4)
        {
            return;
        }

        int back = chosen.back();
        chosen.pop_back();

        int append_current;

        append_current = back * 10;

        append_current += s[index] - '0';

        if (back != 0 && append_current <= 255)
        {
            chosen.push_back(append_current);

            backtrack(chosen, s, index + 1);

            chosen.pop_back();
        }

        chosen.push_back(back);

        chosen.push_back(s[index] - '0');

        backtrack(chosen, s, index + 1);

        chosen.pop_back();
    }

	vector<string> restoreIpAddresses(string s) {
        vector<int> chosen;

        chosen.push_back(s[0] - '0');

        backtrack(chosen, s, 1);

        return result;
    }
private:
    vector<string> result;
};
