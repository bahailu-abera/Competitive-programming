class Node {
public:
    bool isWord;
    int val;
    vector<Node*> children;

    Node()
    {
        isWord = false;
        val = 0;
        children = vector<Node*>(26, nullptr);
    }
};


class Trie {
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string& word, int val)
    {
        auto current = root;

        for (char ch: word)
        {
            if (!current->children[ch - 'a'])
                current->children[ch - 'a'] = new Node();

            current = current->children[ch - 'a'];
        }

        current->isWord = true;
        current->val = val;
    }

    int helper(Node* current)
    {
        if (current == nullptr)
            return 0;

        int value = current->val;

        for (int i = 0; i < 26; i++)
        {
            if (current->children[i])
                value += helper(current->children[i]);
        }

        return value;
    }

    int findSum(string& prefix)
    {
        auto current = root;

        for (int i = 0; i < (int)prefix.size() - 1; i++)
        {
            if (!current->children[prefix[i] - 'a'])
                return 0;

            current = current->children[prefix[i] - 'a'];
        }

        return helper(current->children[prefix.back() - 'a']);
    }

private:
    Node *root;
};

class MapSum {
public:
    MapSum() {

    }

    void insert(string key, int val) {
        trie.insert(key,  val);
    }

    int sum(string prefix) {
        return trie.findSum(prefix);
    }

private:
    Trie trie;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
