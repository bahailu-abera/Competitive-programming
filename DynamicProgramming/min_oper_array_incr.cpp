class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int prev_swap = 1, prev_no_swap = 0;

        for (int i = 1; i < n; i++)
        {
           int curr_swap = n, curr_no_swap = n;

           if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
           {
               curr_swap = prev_swap + 1;
               curr_no_swap = prev_no_swap;
           }

           if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i])
           {
               curr_no_swap = min(curr_no_swap, prev_swap);
               curr_swap = min(prev_no_swap + 1, curr_swap);
           }

           prev_swap = curr_swap;
           prev_no_swap = curr_no_swap;
        }

        return min(prev_swap, prev_no_swap);
    }
};
