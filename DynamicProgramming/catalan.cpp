class Solution {
public:
	vector<int> memo;

	Solution() : memo(64, -1)
	{
	}

	int numTrees(int n) {
		if (n == 0)
			return 1;

		if (memo[n] != -1)
			return memo[n];

		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			count += numTrees(i - 1) * numTrees(n - i);
		}

		memo[n] = count;

		return memo[n];
	}
};
