class Solution {
public:
    int getLucky(string s, int k) {
        string num_string = "";
        for (char c: s) {
            num_string +=  to_string(c - 'a' + 1);
        }
        
        long long res = 0, ans = 0;
        for (char c: num_string) {
            res += (c - '0');
        }
        
        while (--k) {
            ans = 0;
            while (res) {
                ans += (res % 10);
                res /= 10;
            }
            res = ans;
        }
        return res;
    }
};