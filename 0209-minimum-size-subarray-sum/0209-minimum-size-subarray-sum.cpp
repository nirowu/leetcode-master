class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sublength;
        int ans = INT_MAX;
        int sum = 0;
        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= target){
                sublength = j - i + 1;
                if (sublength < ans) {
                    ans = sublength;
                }
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX? 0: ans;
    }
};