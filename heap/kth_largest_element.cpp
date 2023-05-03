class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        comp = [](int a, int b) { return a > b; };
        pq = priority_queue<int, vector<int>, decltype(comp)>(comp);
        this->k = k;

        for (int n: nums) {
            add(n);
        }
    }

	int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }

private:
    int k;
    function<bool(int, int)> comp;
    priority_queue<int, vector<int>, decltype(comp)> pq;
};
