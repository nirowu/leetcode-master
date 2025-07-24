class Solution {
public:
    bool isPalindrome(string s) {

        string newS = "";
        for (auto &c: s) {
            if (std::isalpha(c)) {
                newS += std::tolower(c);
            }
            else if(std:: isdigit(c)) {
                newS += c;
            }
        }

        int left = 0, right = newS.size()-1;
        while(left < right){
            if (newS[left++] != newS[right--]) {
                return false;
            }
        }
        return true;
    }
};