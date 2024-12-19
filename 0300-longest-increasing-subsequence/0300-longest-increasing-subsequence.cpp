class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        int k = 1;
        int dp[2505][2505] = {0}; 
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 1; i < m; i++) {
            if (sorted_nums[i] != sorted_nums[i-1]) {
                sorted_nums[k++] = sorted_nums[i];
            }
        }

        dp[0][0] = (nums[0] == sorted_nums[0]) ? 1 : 0;
        for (int i = 1; i < m; i++) {
            dp[i][0] = (nums[i] == sorted_nums[0]) ? 1 : dp[i-1][0];
        }
        for (int j = 1; j < k; j++) {
            dp[0][j] = (nums[0] == sorted_nums[j]) ? 1 : dp[0][j-1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < k; j++) {
                if (nums[i] == sorted_nums[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m-1][k-1];
    }
};
