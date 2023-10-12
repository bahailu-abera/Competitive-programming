/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    void dfs(NestedInteger nestedInt)
    {
        if (nestedInt.isInteger())
            Q.push(nestedInt.getInteger());
        else
         {
             auto current = nestedInt.getList();

             for (int i = 0; i < (int)current.size(); i++)
                dfs(current[i]);
         }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < (int)nestedList.size(); i++)
            dfs(nestedList[i]);
    }

    int next() {
        int front = Q.front();

        Q.pop();

        return front;
    }

    bool hasNext() {
        return !Q.empty();
    }
private:
    queue<int> Q;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
