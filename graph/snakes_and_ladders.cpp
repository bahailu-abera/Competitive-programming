class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = rows;
        int n = rows * cols;
        int steps = 0;
        vector<int> visited(n + 1);
        queue<int> Q;

        Q.push(1);

        while (!Q.empty())
        {
            int level = (int)Q.size();
            for (int i = 0; i < level; i++)
            {
                int current = Q.front();
                Q.pop();

                if (current == n)
                    return steps;

                for (int next = current + 1; next <= std::min(current + 6, n); next++)
                {
                    if (!visited[next])
                    {
                        visited[next] = 1;
                        int row = (n - next) / rows;
                        int col = (next - 1) % cols;

                        if ((rows % 2 == 0 && row % 2 == 0) || (rows % 2 && row % 2))
                            col = cols - (col + 1);

                        if (board[row][col] == -1)
                            Q.push(next);

                        else
                        {
                            Q.push(board[row][col]);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
