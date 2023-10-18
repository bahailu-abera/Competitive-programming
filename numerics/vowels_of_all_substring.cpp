string vowels = "aeiou";

class Solution {
public:
    bool isvowel(char ch)
    {
        for (char c : vowels)
            if (c == ch)
                return true;

        return false;
    }

    long long countVowels(string word) {
        int n = (int)word.size();
        long long result = 0;

        for (int i = 0; i < n; i++)
        {
            if (isvowel(word[i]))
            {
                result += (long long)(i + 1)* (long long)(n - i);
            }
        }

        return result;
    }
};
