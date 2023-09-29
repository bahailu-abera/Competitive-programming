class Node {
public:
    bool isWord;
    vector<Node*> children;

    Node()
    {
        isWord = false;
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

        for (char ch: word)
        {
            if (!current->children[ch - 'a'])
                current->children[ch - 'a'] = new Node();

            current = current->children[ch - 'a'];
        }

        current->isWord = true;
    }

    bool search(string& prefix)
    {
        auto current = root;

        for (char ch: prefix)
        {
            if (!current->children[ch - 'a'])
                return false;

            current = current->children[ch - 'a'];
        }

        return current->isWord;
    }

private:
    Node* root;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string result;
        Trie trie;

        sort(words.begin(), words.end());

        for (auto word: words)
        {
            string prev = word;
            prev.pop_back();

            if (prev.empty() || trie.search(prev))
            {
                trie.insert(word);

                if (word.size() > result.size())
                    result = word;
            }
        }

        return result;
    }
};
