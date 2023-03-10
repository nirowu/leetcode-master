class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == cur) {
                cnt ++;
            }
            else if (cnt > 0) {
                cnt --;
            }
            else {
                cur = nums[i];
                cnt = 1;
            }
        }
        return cur;
    }
};