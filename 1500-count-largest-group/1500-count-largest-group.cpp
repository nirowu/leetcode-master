class Solution {
public:
    int cntSum(int n) {
        int ans = 0;
        while(n) {
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        int maxSize = 0, ans = 0;
        vector<int> arr(50, 0);
        for (int i = 1; i <= n; i++) {
            int curDigitSum = cntSum(i);
            arr[curDigitSum]++;
            maxSize = max(maxSize, arr[curDigitSum]);
        }
        for (auto nums : arr) {
            if (nums == maxSize) ans++;
        }
        return ans;
    }
};