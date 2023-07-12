class MyQueue {
public:
    stack<int>a,b;

    MyQueue() {
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int ret = peek();
        if (ret != NULL) {
            b.pop();
        }
        return ret;
    }
    
    int peek() {
        if (empty()) {
            return NULL;
        }
        int ret;
        if (!b.empty()) {
            ret = b.top(); 
        }
        else{
            while(!a.empty()){
                b.push(a.top());    a.pop();
            }
            ret = b.top();
        }
        return ret;
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */