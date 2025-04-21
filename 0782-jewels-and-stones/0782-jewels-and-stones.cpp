class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (auto c: jewels) {
            for (auto s: stones) {
                if (c==s) ans++;
            }
        }
        return ans;
    }
};