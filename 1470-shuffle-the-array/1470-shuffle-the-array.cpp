class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int cnt = 0;
        for (int i = 0 ; i < n; i++) {
            ans[cnt++] = nums[i];
            ans[cnt++] = nums[i + n];
        }
        return ans;
    }
};