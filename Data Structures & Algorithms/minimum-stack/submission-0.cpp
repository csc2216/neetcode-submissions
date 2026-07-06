class MinStack {
private:
    stack<int> ms, min;

public:
    MinStack() {

    }
    
    void push(int val) {
        ms.push(val);
        if (min.empty() || val <= min.top()) min.push(val);
    }
    
    void pop() {
        if (ms.top() == min.top()) min.pop();
        ms.pop();
    }
    
    int top() {
        return ms.top();
    }
    
    int getMin() {
        return min.top();
    }
};
