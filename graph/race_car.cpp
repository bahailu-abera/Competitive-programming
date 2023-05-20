class Solution {
public:
    int racecar(int target) {
        unordered_set<string> visited;
        string key = to_string(0) + "," + to_string(1);
        int step = 0;
        queue<pair<int, int>> Q;

        visited.insert(key);
        Q.push({0, 1});

        while (!Q.empty())
        {
            int size = int(Q.size());

            while (size--)
            {
                int pos = Q.front().first;
                int speed = Q.front().second;
                Q.pop();

                if (pos == target)
                    return step;

                int newPos = pos + speed;
                int newSpeed = speed * 2;

                string key = to_string(newPos) + "," + to_string(newSpeed);
                if (!visited.count(key) && abs(newPos - target) < target)
                {
                    visited.insert(key);
                    Q.push({newPos, newSpeed});
                }

                newPos = pos;
                newSpeed = speed < 0 ? 1: -1;
                key = to_string(newPos) + "," + to_string(newSpeed);
                if (!visited.count(key) && abs(newPos - target) < target)
                {
                    visited.insert(key);
                    Q.push({newPos, newSpeed});
                }
            }

            step++;
        }

        return -1;
    }
};
