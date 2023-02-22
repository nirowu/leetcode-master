class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int n, int k, int startx) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = startx; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();

        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        path.clear();
        ans.clear();
        backtracking(n, k, 1);
        return ans;
    }
    
};