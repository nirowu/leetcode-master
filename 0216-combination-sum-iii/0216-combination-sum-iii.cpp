class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int n, int k, int startx, int tempSum) {
        if (path.size() == k && tempSum == n) {
            ans.push_back(path);
            return;
        }
        for (int i = startx; i <= 9; i++) {
            path.push_back(i);
            backtracking(n, k, i+1, tempSum + i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear(); ans.clear();
        backtracking(n, k, 1, 0);
        return ans;
    }
};