class MyQueue {
stack<int> st1, st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                int top = st1.top();
                st1.pop();
                st2.push(top);

            }
        }

        int ans = -1;
        if (!st2.empty()) {
            ans = st2.top();
            st2.pop();
        }
        return ans;
    }
    
    int peek() {
        int back = this->pop();
        st2.push(back);
        return back;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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