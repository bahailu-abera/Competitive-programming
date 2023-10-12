class MyHashMap {
public:
    MyHashMap() {
        dict = vector<int>(size, -1);
    }
    
    void put(int key, int value) {
        dict[key] = value;
    }

    int get(int key) {
        return dict[key];
    }

    void remove(int key) {
        dict[key] = -1;
    }
private:
    int size = 1e6 + 7;
    vector<int> dict;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
