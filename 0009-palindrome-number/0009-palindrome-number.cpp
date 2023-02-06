class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else if (x < 10) return true;
        string str = to_string(x);   
        int i = 0, j = str.size() -1;
        while (i < j) {
            if (str[i] != str[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};