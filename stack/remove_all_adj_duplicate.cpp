class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        string result = "";

        for (char ch: s)
        {
            if (!stack.empty() && stack.top().first == ch)
            {
                stack.push({ch, stack.top().second + 1});
            }
            else
            {
                stack.push({ch, 1});
            }

            if (stack.top().second >= k)
            {
                int remove = k;

                while (remove--)
                    stack.pop();
            }
        }

        while (!stack.empty())
        {
            result += stack.top().first;
            stack.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
