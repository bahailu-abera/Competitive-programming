class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> solved = {{1,2,3},{4,5,0}};
        unordered_set<string> visited;
        function<string(vector<vector<int>>)> to_string = [](vector<vector<int>> grid)
        {
            string number = "";

            for (int i = 0; i < grid.size(); i++)
            {
                for (int num : grid[i])
                    number += num + '0';
            }

            return number;
        };

        function<vector<string>(string s)> findPoss = [&](string s)
        {
            int row, col;
            vector<string> result;
            int pos = -1;
            if (s[0] == '0') row = 0, col = 0, pos = 0;
            else if (s[1] == '0') row = 0, col = 1, pos = 1;
            else if (s[2] == '0') row = 0, col = 2, pos = 2;
            else if (s[3] == '0') row = 1, col = 0, pos = 3;
            else if (s[4] == '0') row = 1, col = 1, pos = 4;

            else row = 1, col = 2, pos = 5;

            for (auto d : directions)
            {
                int new_row = row + d.first;
                int new_col = col + d.second;

                if (new_row < 2 && new_col < 3 && new_row >= 0 && new_col >= 0)
                {
                    int new_pos = new_row * 3 + new_col;
                    string new_s = s;
                    new_s[pos] = s[new_pos];
                    new_s[new_pos] = '0';
                    result.push_back(new_s);
                }
            }

            return result;
        };

        string target = to_string(solved);
        string current = to_string(board);

        if (current == target)
            return 0;

        queue<string> Q;
        int steps = 0;
        Q.push(current);

        while (!Q.empty())
        {
            int level = (int)Q.size();
            for (int i = 0; i < level; i++)
            {
                string current = Q.front();
                Q.pop();

                if (current == target)
                    return steps;
                visited.insert(current);
                for (string s : findPoss(current))
                {
                    if (!visited.count(s))
                    {
                        Q.push(s);
                    }
                }
            }

            steps++;
        }

        return -1;
    }

private:
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
};
