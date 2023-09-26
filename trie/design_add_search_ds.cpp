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

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        auto current = root;

        for (char ch : word)
        {
            if (!current->children[ch - 'a'])
            {
                current->children[ch - 'a'] = new Node();
            }

            current = current->children[ch - 'a'];
        }

        current->isWord = true;
    }

     bool helper(Node* root, string word, int i)
    {
        if (i == (int)word.size())
            return root->isWord;

        if (word[i] == '.')
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (root->children[ch - 'a'] && helper(root->children[ch - 'a'], word, i + 1))
                    return true;
            }

            return false;
        }

        return root-> children[word[i] - 'a'] && helper(root->children[word[i] - 'a'], word, i + 1);
    }

    bool search(string word) {
        return helper(root, word, 0);
    }

private:
    Node *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
