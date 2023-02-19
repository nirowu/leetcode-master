class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        if (words.size() == 0) return ans;
        int hash[26], hashother[26];
        memset(hash, 0 , 26*sizeof(int));
        for (int i = 0; i < words[0].size(); i++) {
            hash[words[0][i]-'a'] ++;
        }
        for (int i = 0; i < words.size(); i++) {
            memset(hashother, 0 , 26*sizeof(int));
            for (int j = 0; j < words[i].size(); j++) {
                hashother[words[i][j]-'a'] ++;
            }
            for (int j = 0; j < 26; j++) {
                hash[j] = min(hash[j], hashother[j]);
            }
        }
        for (int i = 0; i < 26; i++) {
            while (hash[i] --) {
                string s(1, i + 'a');
                ans.push_back(s);
            }
        }
        return ans;
    }
};