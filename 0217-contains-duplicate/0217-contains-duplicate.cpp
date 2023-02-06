class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int temp = s.count(nums[i]);
            if(temp >= 1) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};