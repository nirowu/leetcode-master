class Solution {
private:
    const string mp[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

public:
    vector<string> ans;
    void backtracking(string digits, int idx, const string& path) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }
        int digit = digits[idx] - '0';
        for (int i = 0; i < mp[digit].size(); i++) {
            backtracking(digits, idx + 1, path + mp[digit][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return ans;
        backtracking(digits, 0, "");
        return ans;
    }
};