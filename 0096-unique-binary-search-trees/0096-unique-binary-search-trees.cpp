class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {1, 1};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += (dp[j] * dp[i-1-j]);
            }
        }

        return dp[n];
    }
};