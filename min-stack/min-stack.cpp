class MinStack {
public:
     stack<int>s;
     stack<int>mini;
     
    MinStack() {
        mini.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        if(val<=mini.top()){
            mini.push(val);
        }
    }
    
    void pop() {
    
        if(s.top()==mini.top()){
            mini.pop();
        
        }
        s.pop();
        if(mini.empty()){
            mini.push(INT_MAX);
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
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