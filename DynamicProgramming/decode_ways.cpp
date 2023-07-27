/**
   solution : 1
   Recursive based dynamic solution
 **/
class Solution {
public:
    int dp(int pointer, string s, vector<int>& memo)
    {
        int sum = 0;
        int ways = 0;
        int n = (int)s.size();

        if (pointer >= n)
            return (1);

        if (s[pointer] == '0')
            return 0;

        if (memo[pointer] != -1)
            return memo[pointer];

        for (int i = pointer; i < n; i++)
        {
            sum *= 10;
            sum += s[i] - '0';

            if (sum > 0 && sum <= 26)
            {
                ways += dp(i + 1, s, memo);
            }

            else
            {
                break;
            }
        }

        return memo[pointer] = ways;
    }

    int numDecodings(string s) {
        int n = (int)s.size();
        vector<int> memo(n, -1);

        return dp(0, s, memo);
    }
};

/**
   solution 2: bottom up dynamic solution
 **/
class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.size();
        vector<int> memo(n + 1, 0);

        memo[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            int sum = 0;
            int right = i;

            while (right < n)
            {
                sum *= 10;
                sum += s[right++] - '0';

                if (sum > 0 && sum <= 26)
                    memo[i] += memo[right];

                else
                    break;
            }
        }

        return memo[0];
    }
};
