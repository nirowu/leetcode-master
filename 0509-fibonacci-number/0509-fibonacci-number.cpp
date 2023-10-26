class Solution {
public:
    int fib(int n) {
        int dp[40] = {0, 1};
        for (int i = 2; i < 40; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};