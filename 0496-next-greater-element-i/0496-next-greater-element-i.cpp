class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i = 0, j = 0;
        bool isFind = false;
        for (i = 0; i < nums1.size(); i++) { //nums1[i]
            isFind = false;
            for (j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    break;
                }
            }
            for (; j < nums2.size();j++) {
                if (nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    isFind = true;
                    break;
                }
            }
            if (!isFind) ans.push_back(-1);
        }
        return ans;
    }
};