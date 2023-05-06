class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, j = 0;
        priority_queue<pair<int, pair<int, int> >,
                   vector<pair<int, pair<int, int> > >,
                   greater<pair<int, pair<int, int> > > >
        pq;
        vector<vector<int>> pairs;
        set<pair<int, int>> visited;

        pq.push(make_pair(nums1[i] + nums2[j], make_pair(i, j)));
        visited.insert(make_pair(0, 0));

        while (k-- > 0 && !pq.empty())
        {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();
            i = current.second.first;
            j = current.second.second;
            pairs.push_back({nums1[i], nums2[j]});

            if (i + 1 < nums1.size())
            {
                int sum = nums1[i + 1] + nums2[j];
                pair<int, int> Index = make_pair(i + 1, j);

                if (visited.find(Index) == visited.end())
                {
                    pq.push(make_pair(sum, Index));
                    visited.insert(Index);
                }
            }

            if (j + 1 < nums2.size())
            {
                int sum = nums1[i] + nums2[j + 1];
                pair<int, int> Index = make_pair(i, j + 1);

                if (visited.find(Index) == visited.end())
                {
                    pq.push(make_pair(sum, Index));
                    visited.insert(Index);
                }
            }
        }

        return pairs;
    }
};
