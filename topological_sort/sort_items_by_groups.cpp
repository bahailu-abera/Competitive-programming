class Solution {
public:
	vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
		unordered_map<int, unordered_set<int>> group_graph;
		vector<vector<int>> item_graph(n);
		unordered_map<int, int> group_indegree;
		unordered_map<int, vector<int>> item_group;
		vector<int> item_indegree(n);

		int g = m;
		for (int i = 0; i < n; i++)
		{
			if (group[i] == -1) group[i] = g++;  // assign unique Id for all the groups
			item_group[group[i]].push_back(i);
		}

		for (int i = 0; i < n; i++)
		{
			for (auto bf : beforeItems[i])
			{
				if (group[bf] == group[i])
					item_graph[bf].push_back(i), item_indegree[i]++;

				else if (!group_graph[group[bf]].count(group[i]))
				{
					group_graph[group[bf]].insert(group[i]);
					group_indegree[group[i]]++;
				}
			}
		}

		queue<int> Q;
		vector<int> group_order;

		for (auto& [g, f] : item_group)
		{
			if (group_indegree[g] == 0)
				Q.push(g);
		}

		// First by considering each group as a node we sort them topologically
		while (!Q.empty())
		{
			int current = Q.front();
			group_order.push_back(current);
			Q.pop();

			for (int adj : group_graph[current])
				if (--group_indegree[adj] == 0)
					Q.push(adj);
		}


		if (group_order.size() != item_group.size())
			return {};

		vector<int> result;

		for (int g : group_order)
		{
			queue<int> Q;
			vector<int> items;

			for (int item : item_group[g])
				if (item_indegree[item] == 0)
					Q.push(item);

			while (!Q.empty())
			{
				int current = Q.front();
				items.push_back(current);

				Q.pop();

				for (int adj : item_graph[current])
					if (--item_indegree[adj] == 0)
						Q.push(adj);
			}

			if (item_group[g].size() != items.size())
				return {};

			result.insert(result.end(), items.begin(), items.end());
		}

		return result;
	}
};
