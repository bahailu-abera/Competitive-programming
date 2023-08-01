class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int num_req = (int)requests.size();
        int num_subsets = pow(2, num_req);
        int max_request = 0;

        for (int i = 1; i <= num_subsets; i++)
        {
            vector<int> transfer(n, 0);
            int current = 0;

            for (int j = 0; j < num_req; j++)
            {
                int mask = (i >> j) & 1;

                if (mask)
                {
                    transfer[requests[j][0]]--;
                    transfer[requests[j][1]]++;
                    current++;
                }
            }

            for (int trans : transfer)
            {
                if (trans != 0)
                {
                    current = 0;
                    break;
                }
            }

            max_request = std::max(max_request, current);
        }

        return max_request;
    }
};
