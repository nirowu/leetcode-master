class Solution {
public:
    int trap(vector<int>& height) {
        int  ans = 0;
        int left = 0, right = height.size()-1;
        int left_max = INT_MIN, right_max = INT_MIN;
        while(left <= right) {
            if (height[left] <= height[right]) {
                left_max = max(height[left], left_max);
                ans += (left_max - height[left]);
                left ++;
            }
            else {
                right_max = max(height[right], right_max);
                ans += (right_max - height[right]);
                right --;
            }
        }
        return ans;
    }
};