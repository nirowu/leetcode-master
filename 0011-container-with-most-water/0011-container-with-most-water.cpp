class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area = 0, MaxArea = 0;
        while(left < right) {
            area = min(height[right], height[left]) * (right - left);
            MaxArea = max(MaxArea, area);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return MaxArea;
    }
};