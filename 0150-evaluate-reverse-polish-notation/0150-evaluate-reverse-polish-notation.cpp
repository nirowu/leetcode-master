class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0, num1, num2;
        stack<int>st;
        for (int i =  0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();
                ans = num1 + num2;
                st.push(ans);

            }
            else if (tokens[i] == "-"){
                num2 = st.top(); st.pop();
                num1 = st.top(); st.pop();
                ans = num1 - num2;
                st.push(ans);

            }
            else if (tokens[i] == "*") {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();
                ans = num1 * num2;
                st.push(ans);

            }
            else if (tokens[i] == "/") {
                num2 = st.top(); st.pop();
                num1 = st.top(); st.pop();
                ans = num1 / num2;
                st.push(ans);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};