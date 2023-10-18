class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity) {
    }

    int get(int key) {
        auto pos = cache_data.find(key);

        if (pos == cache_data.end())
            return -1;

        int value = pos->second->second;
        order.erase(pos->second);
        order.emplace_back(key, value);

        cache_data[key] = prev(order.end());

        return value;
    }

    void put(int key, int value) {
        auto pos = cache_data.find(key);

        if (pos != cache_data.end()) {
            order.erase(pos->second);

            // update the value of the existing key in the cache
            order.emplace_back(key, value);
            cache_data[key] = prev(order.end());

            return;
        }

        if ((int)cache_data.size() == capacity) {
            auto lru = order.front();
            cache_data.erase(lru.first);
            order.pop_front();
        }

        // insert the new key-value pair into the cache
        order.emplace_back(key, value);
        cache_data[key] = prev(order.end());
}

private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache_data;
    list<pair<int, int>> order;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
