class Solution {
public:
    string reorganizeString(string s) {
        int n = (int)s.size();
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        string result(n);

        for (char ch : s)
            freq[ch]++;

        for (auto [ch, f] : freq)
            pq.push({f, ch});

        int i = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            for (int j = i; j < n && top.first--; j += 2)
                result[j] = top.second;

            if (top.first > 0)
                return "";

            i++;
        }
    }
};
