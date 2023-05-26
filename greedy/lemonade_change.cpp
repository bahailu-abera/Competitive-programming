class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for (int b : bills)
        {
            if (b == 5)
                fives++;

            else if (b == 10)
            {
                if (!fives)
                    return false;
                fives--;
                tens++;
            }

            else
            {
               if (!fives || (!tens && fives < 3))
                return false;

                if (tens) tens--, fives--;

                else fives -= 3;
            }
        }

        return true;
    }
};
