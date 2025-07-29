class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr1 [1005], arr2[1005];
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            arr1[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            arr2[nums2[i]] = 1;
        }
        for (int i = 0; i < 1005; i++) {
            if (arr1[i] && arr2[i]) ans.push_back(i); 
        }
        return ans;
    }
};