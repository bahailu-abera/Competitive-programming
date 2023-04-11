/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool inbound(int row, int col, int rowSize, int colSize)
{
	if (row < 0 || row >= rowSize)
		return (false);

	return (col >= 0 && col < colSize);
}

void fill(int **image, int imageSize, int imageColSize, int sr, int sc, int color, int prev)
{
	int directions[4][2] = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}
	};

	if (image[sr][sc] == color)
		return;

	image[sr][sc] = color;
	for (int i = 0; i < 4; i++)
	{
		int new_row = sr + directions[i][0];
		int new_col = sc + directions[i][1];
		if (inbound(new_row, new_col, imageSize, imageColSize) && image[new_row][new_col] == prev)
		{
			fill(image, imageSize, imageColSize, new_row, new_col, color, prev);

		}
	}
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc,
		int color, int* returnSize, int** returnColumnSizes){

	fill(image, imageSize, imageColSize[0], sr, sc, color, image[sr][sc]);

	*returnColumnSizes = malloc(imageSize * sizeof(int));
	for (int i = 0; i < imageSize; i++)
	{
		(*returnColumnSizes)[i] = imageColSize[i];
	}
	*returnSize = imageSize;

	return (image);
}
