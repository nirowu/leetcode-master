class Solution {
public:
    map<pair<int, int>, int> record;
    int dp(int idx, int cur_val, vector<int>&nums, int target) {
        pair<int, int> pii(idx, cur_val);
        if (record.find(pii) != record.end()) return record[pii];
        if (idx < 0 && cur_val == target) {
            return 1;
        }
        else if (idx < 0) return 0;
        
        int neg = dp(idx-1, cur_val-nums[idx], nums, target);
        int pos = dp(idx-1, cur_val+nums[idx], nums, target);
        
        int ans = neg + pos;
        record[pii] = ans;
        
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums.size()-1, 0, nums, target);
    }
};