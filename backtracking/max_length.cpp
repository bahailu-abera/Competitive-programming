class Solution {
public:
	bool isUnique(string s)
	{
		int alpha = 0;

		for (char ch : s)
		{
			int c = ch - 'a';
			int mask = 1 << c;

			if (alpha & mask)
				return false;

			alpha |= mask;
		}

		return true;
	}

	int maxLength(vector<string>& arr) {
		int max_length = 0;
		int n = int(arr.size());

		function<void(string, int)>
			backtrack = [&](string s, int index)
				    {
					    if (!isUnique(s))
						    return;

					    max_length = max(max_length, (int)s.size());

					    for (int i = index; i < n; i++)
					    {
						    backtrack(s + arr[i], i + 1);
					    }
				    };

		backtrack("", 0);

		return max_length;
	}
};
