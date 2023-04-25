class Solution {
public:
	bool isValid(int a, int b, int c, int d, int e, int f, int g, int h, int i)
	{
		set<int> s1 = {a, b, c, d, e, f, g, h, i},
			s2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		if (s1 != s2)
			return false;

		if ((a + b + c )!= 15 || (d + e + f) !=  15 || (g + h + i )!= 15)
			return false;

		if ((a + d + g) != 15 || (b + e + h) != 15 || (c + f + i) != 15)
			return false;

		if ((a + e + i) != 15 || (c + e + g) != 15)
			return false;

		return true;
	}

	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int count = 0;
		int rows, cols;

		rows = grid.size();
		cols = grid[0].size();

		for (int i = 0; i < (rows - 2); i++)
		{
			for (int j = 0; j < (cols - 2); j++)
			{
				if (isValid(grid[i][j], grid[i][j + 1],
					    grid[i][j + 2], grid[i + 1][j],
					    grid[i + 1][j + 1], grid[i + 1][j + 2],
					    grid[i + 2][j], grid[i + 2][j + 1],
					    grid[i + 2][j + 2]))
					count++;
			}
		}

		return (count);
	}
};
