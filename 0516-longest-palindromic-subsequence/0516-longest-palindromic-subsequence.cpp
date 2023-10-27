class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0 || s.size() == 1) return s.size();
        int dp[1005][1005];
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = s.size()-1; i >= 0 ; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        // for ( int i = 0; i < s.size(); i++) {
        //     for (int j =0; j < s.size() ; j++) {
        //         cout<< dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][s.size()-1];
        
    }
};