class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (index.count(val))
            return false;

        index[val] = (int)values.size();

        values.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (!index.count(val))
            return false;

        int idx = index[val];

        values[idx] = values.back();
        index[values.back()] = idx;
        values.pop_back();

        index.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();

        return values[randomIndex];
    }
private:
    vector<int> values;
    unordered_map<int, int> index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
