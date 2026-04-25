class MinStack {
public:
    stack<int> s1, s2;

    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        
        if (s2.empty() || s2.top() >= val) {
            s2.push(val);
        }
    }
    
    void pop() {
        int topVal = s1.top();

        if (s2.top() == topVal) {
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
