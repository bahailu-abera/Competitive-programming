public:
    int maxProduct(vector<string>& words) {
        int max_length = 0;
        int len = (int)words.size();
        vector<pair<int, int>> word_bitmask(len);


        for (int i = 0; i < len; i++)
        {
            int bitmask = 0;

            for (char ch : words[i])
            {
                int num = ch - 'a';
                bitmask |= (1 << num);
            }

            word_bitmask[i] = {(int)words[i].size(), bitmask};
        }

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
               if ((word_bitmask[i].second & word_bitmask[j].second) == 0)
               {
                   max_length = std::max(max_length, word_bitmask[i].first * word_bitmask[j].first);
               }
            }
        }

        return max_length;
    }
};
