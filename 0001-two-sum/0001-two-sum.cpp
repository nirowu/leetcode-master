class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        vector<int>ans(2);
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans[0] = i;
                ans[1] = mp[nums[i]];
                break;
            }
            mp[target - nums[i]] = i;

        }
        return ans;
    }
};