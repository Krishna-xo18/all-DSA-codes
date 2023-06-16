class MyStack {
public:
  deque<int>q;
  //int lastpush;
    MyStack() {
      
    }
    
    void push(int x) {
        q.push_front(x);
        
    }
    
    int pop() {
        int x=q.front();
        q.pop_front();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(!q.empty()){
            return false;
        }
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */