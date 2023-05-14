class Solution {
public:
    int n = 0, m = 0;

    void dfs(vector<vector<char>>& board, int row, int col)
    {
        if (board[row][col] == 'X')
            return;

        board[row][col] = '1';
        for (auto d: directions)
        {
            int new_row = row + d.first;
            int new_col = col + d.second;

            if (new_col >= 0 && new_row >= 0 && new_row < n && new_col < m && board[new_row][new_col] == 'O')
                dfs(board, new_row, new_col);
        }
    }

	void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n ; i++)
            dfs(board, i, 0), dfs(board, i, m - 1); // check for the left column edge and the right most column

        for (int i = 0; i < m; i++)
            dfs(board, 0, i), dfs(board, n - 1, i); // check for the top and bottom rows


        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == '1')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }

private:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
};
