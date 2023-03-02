class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used, int startx) {
        ans.push_back(path);
        for (int i = startx; i < nums.size(); i++) {
            if (i > 0  && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used, i + 1);
            path.pop_back();
            used[i] = false;
        }
        
    }
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used, 0);
        return ans;
    }
};