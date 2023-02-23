class Solution {
private:
    vector<int>path;
    vector<vector<int>>ans;
    void backtracking(vector<int>& candidates, vector<bool>& used, int target, int sum, int startx) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = startx; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0  && candidates[i] == candidates[i-1]  && !used[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, used, target, sum + candidates[i], i + 1);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used (candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, used, target, 0, 0);
        return ans;
    }
};