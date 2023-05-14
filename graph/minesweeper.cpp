class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();

        function<void(int, int)> dfs = [&](int r, int c)
        {
            if (board[r][c] == 'M')
            {
                board[r][c] = 'X'; // end of the game end of the world!
                return;
            }

            if (board[r][c] != 'E')
                return; // Nothing to explore

            int mines = 0;
            vector<pair<int, int>> validMoves;
            for (auto d : directions)
            {
                int new_r = r + d.first;
                int new_c = c + d.second;
                if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < m)
                {
                    validMoves.push_back({new_r, new_c});
                    if (board[new_r][new_c] == 'M')
                        mines++;
                }
            }

            if (mines > 0)
            {
                board[r][c] = mines + '0'; // We get mines
                return;
            }

            board[r][c] = 'B';
            for (auto d : validMoves)
                dfs(d.first, d.second);
        };

        dfs(click[0], click[1]);

        return board;
    }

private:
    vector<pair<int, int>> directions = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0},
        {1,1},
        {-1,-1},
        {1,-1},
        {-1,1}
    };
};
