class Node {
public:
    int count;
    unordered_map<char, Node*> children;

    Node()
    {
        count = 0;
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
            if (!current->children[ch])
                current->children[ch] = new Node();

            current->children[ch]->count++;

            current = current->children[ch];
        }
    }

    int prefixScores(string& word)
    {
        int score = 0;
        auto current = root;

        for (char ch: word)
        {
            score += current->children[ch]->count;

            current = current->children[ch];
        }

        return score;
    }

private:
    Node* root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = (int)words.size();
        vector<int> answer(n);
        Trie trie;

        for (string& word: words)
            trie.insert(word);

        for (int i = 0; i < n; i++)
            answer[i] = trie.prefixScores(words[i]);

        return answer;
    }
};
