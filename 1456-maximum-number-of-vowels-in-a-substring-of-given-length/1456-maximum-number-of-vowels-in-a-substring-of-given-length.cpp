class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>map {'a', 'e', 'i', 'o', 'u'};
        int maxLength = 0, curLength = 0;
        for (int i = 0; i < k; i++) {
            if (map.count(s[i])) {
                maxLength++;
            }
        }
        curLength = maxLength;

        for (int i = k; i < s.size(); i ++) {
            if (map.count(s[i]) && !map.count(s[i-k])) {
                curLength ++;
            }
            if (!map.count(s[i]) && map.count(s[i-k])) {
                curLength --;
            }
            maxLength = max(curLength, maxLength);
        }
        return maxLength;
    }
};