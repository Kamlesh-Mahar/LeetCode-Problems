class MinStack {
private:
    stack<int> regularStack;
    stack<int> minStack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        regularStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (regularStack.top() == minStack.top()) {
            minStack.pop();
        }
        regularStack.pop();
    }
    
    int top() {
        return regularStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */