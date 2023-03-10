class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int tempSum, int startx) {
        if (tempSum > target) {
            return;
        }
        if (tempSum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = startx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target, tempSum + candidates[i] , i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear(); path.clear();
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};