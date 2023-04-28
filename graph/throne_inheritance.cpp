struct Parent
{
	string Name;
	bool isalive;
	deque<Parent *> children;
	Parent *parent;
};

class ThroneInheritance {
private:
	Parent *king, d;
	map<string, Parent*> memo;

public:
	ThroneInheritance(string kingName) {
		king = new Parent();
		king->Name = kingName;
		king->isalive = true;
		king->parent = nullptr;
		king->children = deque<Parent *>();
		memo[kingName] = king;
	}

	void birth(string parentName, string childName) {
		Parent *p, *child;

		p = memo[parentName];
		child = new Parent();

		child->Name = childName;
		child->isalive = true;
		child->children = deque<Parent *>();

		child->parent = p;
		memo[childName] = child;
		p->children.push_front(child);
	}

	void death(string name) {
		Parent *p = memo[name];
		p->isalive = false;
	}

	vector<string> getInheritanceOrder() {
		vector<string> order;

		Parent *current = king;
		stack<Parent *> S;

		S.push(current);

		while (!S.empty())
		{

			current = S.top();
			S.pop();

			if (current->isalive)
				order.push_back(current->Name);

			for (auto child : current->children)
			{
				S.push(child);
			}
		}

		return order;
	}
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
