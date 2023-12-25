class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[1690] = {1};
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(2*dp[i2], 3*dp[i3]);
            dp[i] = min(dp[i], 5*dp[i5]);
            if (dp[i] == 2*dp[i2]) i2++;
            if (dp[i] == 3*dp[i3]) i3++;
            if (dp[i] == 5*dp[i5]) i5++;
            // cout<< dp[i]<<" ";
        }
        return dp[n-1];
    }
};