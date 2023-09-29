class Node {
public:
    vector<Node*> children;

    Node()
    {
        children = vector<Node*>(2, nullptr);
    }
};

class Trie {
public:
    Trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        auto current = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;

            if (!current->children[bit])
                current->children[bit] = new Node();

            current = current->children[bit];
        }
    }

    int maxXor(int n)
    {
        auto current = root;
        int answer = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;

            if (current->children[bit ^ 1])
            {
                answer |= 1 << i;
                current = current->children[bit ^ 1];
            }
            else if (current->children[bit])
            {
                current = current->children[bit];
            }
            else
            {
                break;
            }
        }

        return answer;
    }

private:
    Node* root;
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;

        Trie trie;

        for (int n : nums)
        {
            trie.insert(n);

            result = max(result, trie.maxXor(n));
        }

        return result;
    }
};
