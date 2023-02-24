class Solution {
private:
    vector<vector<string>> ans;
    vector<string> path;
    bool isPalindrome (const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    void backtracking (const string& s, int startx) {
        if (startx >= s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = startx; i < s.size(); i++) {
            if (isPalindrome(s, startx, i)) {
                string str = s.substr(startx, i - startx + 1);
                path.push_back(str);
            }
            else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};