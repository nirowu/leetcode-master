class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        string newString = "";
        for (char c: s) {
            if (c == '*') {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
        while(!stk.empty()) {
            newString += stk.top();
            stk.pop();
        }
        reverse(newString.begin(), newString.end());
        return newString;
    }
};