class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        stack.push(val);

        if (min_stack.empty())
            min_stack.push(val);
        else
            min_stack.push(min(min_stack.top(), val));
    }

    void pop() {
        stack.pop();
        min_stack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
private:
    std::stack<int> stack;
    std::stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
