class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        vector<string> modes(k);

        auto comp = [](pair<string, int> a, pair<string, int> b) ->bool {
            if (a.second == b.second)
                return a.first < b.first;

            return a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)>pq(comp);

        for (auto s: words) freq[s]++;

        for (auto [s, f]: freq)
        {
            pq.push(make_pair(s, f));
            if (pq.size() > k)
                pq.pop();
        }

        int i = k;
        while (!pq.empty())
        {
            pair<string, int> t = pq.top();
            pq.pop();
            modes[--i] = t.first;
        }

        return modes;
    }
};
