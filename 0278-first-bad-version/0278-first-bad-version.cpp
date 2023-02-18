// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    bool flag;
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            flag = isBadVersion(mid);
            if (!flag) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
};