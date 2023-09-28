class Node {
public:
    int words;
    vector<Node*> children;

    Node()
    {
        words = 0;
        children = vector<Node*>(26, nullptr);
    }
};

class Trie {
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string& word)
    {
        auto current = root;

        for (char ch : word)
        {
            if (!current->children[ch - 'a'])
                current->children[ch - 'a'] = new Node();

            current = current->children[ch - 'a'];
        }

        current->words += 1;
    }

    int helper(Node* current, string& s, int idx)
    {
        int result = 0;

        for (int i = 0; i < 26; i++)
        {
            if (current->children[i] == nullptr)
                continue;

            int index = s.find(i + 'a', idx);

            if (index == string::npos)
                continue;

            result += current->children[i]->words;

            result += helper(current->children[i], s, index + 1);
        }

        return result;
    }

    int numMatchingSubseq(string& s)
    {
        return helper(root, s, 0);
    }

private:
    Node* root;
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie trie;

        for (auto& word: words)
            trie.insert(word);

        return trie.numMatchingSubseq(s);
    }
};
