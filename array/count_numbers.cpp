class Solution {
public:
	Solution()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	}

	int reverse(int n)
	{
		int reversed_number = 0, remainder;

		while(n != 0) {
			remainder = n % 10;
			reversed_number = reversed_number * 10 + remainder;
			n /= 10;
		}

		return reversed_number;
	}

	int countDistinctIntegers(vector<int>& nums) {
		map<int, int> hash;

		for (int i = 0; i < nums.size(); i++)
		{
			hash[nums[i]] = 1;
			hash[reverse(nums[i])] = 1;
		}

		return hash.size();
	}
};
