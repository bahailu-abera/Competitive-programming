class Solution {
public:
    vector<string> move(string current)
    {
        vector<string> result;

        for (int i = 0; i < 4; i++)
        {
            int ch = current[i] - '0';
            string forward = current;
            string backward = current;
            forward[i] = ((ch + 1) % 10) + '0';
            backward[i] = ((ch - 1 + 10) % 10) + '0';

            result.push_back(forward);
            result.push_back(backward);
        }

        return result;
    }
    int openLock(vector<string>& deadends, string target) {
        map<string, bool> deads;
        queue<string> Q;
        int steps = 0;

        if (target == "0000")
            return 0;

        for (auto &dead: deadends)
            deads[dead] = true;

        if (deads["0000"])
            return -1;

        Q.push("0000");
        while (!Q.empty())
        {
            const int level = Q.size();
            for (int i = 0; i < level; i++)
            {
                string current = Q.front();
                Q.pop();

                vector<string> next_move = move(current);
                for (auto& next : next_move)
                {
                    if (!deads[next])
                    {
                        if (next == target)
                            return steps + 1;

                        deads[next] = true;
                        Q.push(next);
                    }
                }
            }

            steps++;
        }

        return (-1);
    }
};
