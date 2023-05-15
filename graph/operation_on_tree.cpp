class LockingTree {
public:
    LockingTree(vector<int>& p) {
        n = p.size();
        parent = p;
        locked = vector<int>(n, -1);
        graph = vector<vector<int>>(n);

        for (int i = 1; i < n; i++)
        {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
    }

	bool lock(int num, int user) {
        if (locked[num] != -1)
            return false;

        locked[num] = user;
        return true;
    }

	bool unlock(int num, int user) {
        if (locked[num] != user)
            return false;

        locked[num] = -1;

        return true;
    }

   bool isAncestorLocked(int node)
    {
        if (node == -1)
            return false;

        if (locked[node] != -1)
            return true;

        return isAncestorLocked(parent[node]);
    }

	bool isDescedentLocked(int node)
    {
        for (int child : graph[node])
        {
            if (child != parent[node] && locked[child] != -1)
                return true;

            if (child != parent[node] && isDescedentLocked(child))
                return true;
        }

        return false;
    }

    void unlockAll(int node)
    {
        for (int child : graph[node])
        {
            if (child != parent[node])
            {
		    locked[child] = -1;
		    unlockAll(child);
            }
        }
    }
    bool upgrade(int num, int user) {

	    if (locked[num] != -1 || isAncestorLocked(num) || !isDescedentLocked(num))
            return false;

        locked[num] = user;

        unlockAll(num);

        return true;
    }

private:
    int n = 0;
    vector<int> parent;
    vector<int> locked;
    vector<vector<int>> graph;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
