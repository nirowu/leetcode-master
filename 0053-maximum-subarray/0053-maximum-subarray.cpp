class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending = nums[0];
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_ending = max(max_ending + nums[i], nums[i]);
            maxi = max(max_ending, maxi);
        }
        return maxi;
    }
};