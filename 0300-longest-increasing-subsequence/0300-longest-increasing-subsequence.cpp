class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        int k = 1;
        int dp[2505][2505];
        vector<int>sorted_nums;
        sorted_nums.assign(nums.begin(), nums.end());
        sort(sorted_nums.begin(), sorted_nums.end());
        int removed_dup[2505] = {sorted_nums[0]};

        for (int i = 1; i < m; i++) {
            if (sorted_nums[i] != sorted_nums[i-1]) {
                removed_dup[k++] = sorted_nums[i];
            }
        }
        // // test
        // for (int i = 0; i < k; i++) {
        //     cout<<removed_dup[i];
        // }
        // cout<<endl;
        // for (int i = 0; i < m; i++) {
        //     cout<<nums[i];
        // }
        // cout<<endl<<m<<k<<endl;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = (nums[i] == removed_dup[j])? 1:0; //要延續舊的資訊
                    continue;
                }
                else if (i == 0) {
                    dp[i][j] = (nums[i] == removed_dup[j])? 1: dp[i][j-1]; 
                    continue;
                }
                else if (j == 0) {
                    dp[i][j] = (nums[i] == removed_dup[j])? 1: dp[i-1][j]; 
                    continue;

                }
                if (nums[i] == removed_dup[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }
        
        return dp[m-1][k-1];
        
    }
};