class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        int tmp;
        vector<int> ans(2);
        while(left < right) {
            tmp = numbers[left] + numbers[right];
            if (tmp == target) {

                ans[0] = left+1; 
                ans[1] = right+1;
                return ans;
            } 
            else if (tmp < target) {
                left++;
            }
            else {
                right--;
            }

        }
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
};