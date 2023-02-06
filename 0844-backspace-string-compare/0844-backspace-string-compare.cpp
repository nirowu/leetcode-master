class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == '#' && ss.empty()) continue; 
            if (s[i] == '#') {ss.pop(); continue;}
            ss.push(s[i]);
        }
        for (int i = 0 ; i < t.size(); i++) {
            if (t[i] == '#' && tt.empty()) continue; 
            if (t[i] == '#') {tt.pop(); continue;}
            tt.push(t[i]);
        }
        
        while(!ss.empty() && !tt.empty()) {
            if (ss.top() != tt.top()) {
                return false;
            }
            ss.pop(); tt.pop();
        }
        if (ss.empty() && tt.empty()) return true;
        if (ss.empty() || tt.empty()) return false;
        return true;
    }
};