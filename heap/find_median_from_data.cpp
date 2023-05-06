class MedianFinder {
public:
    MedianFinder() {

    }

	void addNum(int num) {
        if (max_heap.size() == 0 || max_heap.top() > num)
            max_heap.push(num);

        else
            min_heap.push(num);

        int min_size = min_heap.size();
        int max_size = max_heap.size();

        if (max_size - min_size > 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        else if (min_size - max_size > 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

	double findMedian() {
        double median;

        if (min_heap.size() == max_heap.size())
        {
            median = (double(min_heap.top()) + double(max_heap.top())) / 2L;
        }

        else if (min_heap.size() < max_heap.size())
            median = max_heap.top();

        else
            median = min_heap.top();

        return median;
    }
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
