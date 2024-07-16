class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1, longest = 0;
        vector<int>cnt(256);
        std::fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0 ; i < s.size(); i++) {
            cnt[s[i]]++;
            while (cnt[s[i]] > 1) {
                left++;
                cnt[s[left]]--;
            }
            longest = max(longest, i-left);
            
        }  
        return longest;
    }
    
};