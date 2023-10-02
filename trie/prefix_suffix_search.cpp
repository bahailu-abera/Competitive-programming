// class WordFilter {
// public:
//     WordFilter(vector<string>& words) {
//         int n = (int)words.size();
//         for (int i = 0; i < n; i++)
//         {
//             int m = (int)words[i].size();
//             string pref = "";

//             for (int j = 0; j < m; j++)
//             {
//                 pref += words[i][j];

//                 for (int k = 0; k < m; k++)
//                 {
//                     string suff = words[i].substr(k, m - k);

//                     index[pref + "*" + suff] = i;
//                 }
//             }
//         }
//     }

//     int f(string pref, string suff) {
//         string key = pref + "*" + suff;
        
//         if (index.count(key))
//             return index[key];

//         return -1;
//     }

// private:
//     unordered_map<string, int> index;
// };

class Node {
public:
    int index;
    vector<Node*> children;

    Node()
    {
        index = -1;
        children = vector<Node*>(27, nullptr);
    }
};

class Trie {
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word, int index)
    {
        auto current = root;

        for (char ch: word)
        {
            if (!current->children[ch - 'a'])
                current->children[ch - 'a'] = new Node();

            current->children[ch - 'a']->index = index;
            current = current->children[ch - 'a'];
        }
    }

    int find(string word)
    {
        auto current = root;

        for (char ch: word)
        {
            if (!current->children[ch - 'a'])
                return -1;

            current = current->children[ch - 'a'];
        }

        return current->index;
    }

private:
    Node* root;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int n = (int)words.size();
        for (int i = 0; i < n; i++)
        {
            int m = (int)words[i].size();

            for (int j = 0; j < m; j++)
            {
               string suff = words[i].substr(j, m - j);

               trie.insert(suff + "{" + words[i], i);
            }
        }
    }

    int f(string pref, string suff) {
        return trie.find(suff + "{" + pref);
    }

private:
    Trie trie;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */