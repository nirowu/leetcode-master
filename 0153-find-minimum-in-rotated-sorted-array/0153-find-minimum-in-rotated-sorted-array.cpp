class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2; 
        int left = 0, right = n-1;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return nums[left];
    }
};