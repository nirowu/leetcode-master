class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i]+1 < 10) {
                digits[i]++;
                break;
            } else if (i != 0) {
                digits[i] = 0;
                continue;
            } else {
                digits.resize(digits.size()+1);
                digits[0] = 1;
            }
        }
        return digits;
    }
};