class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int, int>mp;
        int idx = 0; int isFind;
        for (int i = 0; i < nums2.size(); i++) {
            isFind = 0;
            for (int j = i+1; j < nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    mp[nums2[i]] = nums2[j];
                    isFind = 1;
                    break;
                };
            }
            if (!isFind) mp[nums2[i]] = -1;
        }
        for (auto& i: nums1) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};