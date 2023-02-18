class Solution {
public:
    int longestPalindrome(string s) {
        int lower[26], upper[26];
        for (int i = 0; i < 26; i++) {
            lower[i] =0; upper[i] = 0;
        } 
        for (int i =0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') lower[s[i] - 'a']++;
            if (s[i] >= 'A' && s[i] <= 'Z') upper[s[i] - 'A']++;
        }
        int mid = 0, ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] == 0 && upper[i] == 0) continue;
            else if (lower[i] % 2 || upper[i] %2) mid = 1;
            ans = ans + (lower[i] / 2 ) * 2 + (upper[i] / 2) * 2;
        }
        return ans + mid;
    }
};