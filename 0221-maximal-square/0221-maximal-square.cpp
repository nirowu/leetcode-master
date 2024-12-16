class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[305][305] = {}; // Initialize dp array with zeroes

        int m = matrix.size(), n = matrix[0].size();
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0) && matrix[i][j] == '1') {
                    dp[i][j] = 1;
                }
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi * maxi; // Return the area of the maximal square
    }
};
