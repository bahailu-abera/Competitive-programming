class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p, t, match = 0;

        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());

        p = t = 0;
        for (; t < trainers.size() && p < players.size(); t++)
        {
            if (players[p] <= trainers[t])
                match++, p++;
        }

        return (match);
    }
};
