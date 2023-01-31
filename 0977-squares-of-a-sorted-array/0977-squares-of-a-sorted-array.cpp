class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int cnt = nums.size();
        vector<int>ans(cnt);
        while(cnt--) {
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];
            if(left > right) {
                ans[cnt] = left; 
                i++;
            }
            else {
                ans[cnt] = right;
                j--;
            }
        }
        return ans;
    }
};