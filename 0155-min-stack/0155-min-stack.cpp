class MinStack {
private:
    stack<int> st;
    stack<int> min_st; // ç¨ stack å°±å¤ äºï¼ä¸éè¦ deque

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        } else {
            min_st.push(min_st.top()); // ä¿æå°æå¤§å°
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            min_st.pop();
        }
    }

    int top() {
        return st.empty() ? -1 : st.top();
    }

    int getMin() {
        return min_st.empty() ? -1 : min_st.top();
    }
};
