class Solution {
public:
    bool judgeSquareSum(int c) {
        int low = 0, high = sqrt(c);

        c = (long long)c;
        while (low <= high)
        {
            long long result = (long long )(low * low) + (long long)(high * high);
            if (result == c)
                return (true);
            else if (result < c)
                low += 1;
            else
                high -= 1;
        }

        return (false);
    }
};
