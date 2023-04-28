class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        size_t visited_size = 1;
        queue<int> Q;

        Q.push(0);
        while (!Q.empty())
        {
            int current = Q.front();
            visited[current] = 1;
            Q.pop();

            for (int key : rooms[current])
            {
                if (!visited[key])
                    Q.push(key), visited_size += 1;;

                visited[key] = 1;
            }
        }

        return visited_size == rooms.size();
    }
};
