class Solution {
public:
	void sortColors(vector<int>& nums) {
		int p1 = -1;
		int p2 = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 2 && p2 == -1)
				p2 = i;

			else if (nums[i] == 1)
			{
				if (p2 != -1)
				{
					nums[p2] = 1, nums[i] = 2;
					if (p1 == -1) p1 = p2;
					p2++;
				}

				if (p1 == -1) p1 = i;
			}

			else if (nums[i] == 0)
			{
				if (p1 != -1 && p2 != -1)
					nums[p1] = 0, nums[p2] = 1, nums[i] = 2, p1++, p2++;

				else if (p1 != -1)
					nums[p1] = 0, nums[i] = 1, p1++;

				else if (p2 != -1)
					nums[p2] = 0, nums[i] = 2, p2++;
			}
		}
	}
};
