class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int halfSize = nums.size()/2;
        for (int i = 0; i < nums.size(); i++ ) {
            mp[nums[i]] ++;
            if(mp[nums[i]] > halfSize) {
                return nums[i];
            }
        }
        return 0;
    }
};