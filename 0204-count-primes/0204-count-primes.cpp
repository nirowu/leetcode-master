class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int n_sqr = sqrt(n);
        int dp[5000005] = {1, 1};
        for (int i = 2; i <= n_sqr; i++) {
            if (dp[i] == 0) {
                int temp = i * 2;
                while (temp <= n) {
                    dp[temp] = 1;
                    temp += i;
                }                
            }
        }
        int ret = 0;
        for (int i = 1; i < n; i++) {
            if(dp[i] == 0) ret++;
        }
        return ret;
    }
};