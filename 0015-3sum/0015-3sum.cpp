class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int target = 0, sum = 0;
        int i = 0, j = 0, k = 0;
        for (i; i <= nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            j = i+1, k = nums.size()-1;
            target = -nums[i];
            while(j < k) {
                sum = nums[j] + nums[k];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++; k--;
                }
                else if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ans;
    }
};