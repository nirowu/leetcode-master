class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k %= nums.size();
        int j = 0, n = nums.size();
        vector<int> temp(n);
        for (int i = n - k ; i < n ; i++) {
            temp[j++] = nums[i];
        }
        for (int i = 0; i < nums.size() - k; i++) {
            temp[j++] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++ ) {
            nums[i] = temp[i];
        }
    }
};