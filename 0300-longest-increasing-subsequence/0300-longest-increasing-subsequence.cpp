class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr(nums); //sorted nums array
        sort(arr.begin(), arr.end());
        int dp[2505][2505];
            
        for (int j = 1; j <= nums.size(); j++) {
            for (int i = 1; i <= nums.size(); i++) {
                if (j >= 2) {
                    if (arr[j-1] == arr[j-2]){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                        continue;
                    }
                }
                if (nums[i-1] == arr[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                }
            }
        }

        return dp[nums.size()][nums.size()];
    }
};