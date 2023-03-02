class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtracking(vector<int>& nums, int startx) {
        ans.push_back(tmp);
        if (startx >= nums.size()) return;
        for (int i = startx; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtracking(nums, i + 1);
            tmp.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear(); tmp.clear();
        backtracking(nums, 0);
        return ans;
    }
};