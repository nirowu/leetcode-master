class Solution {
public:
    vector<vector<int>> ans;
    void perm(vector<int>&n, int i) {
        if (i == n.size()) {
            ans.push_back(n);
            return;
        }
    
        for (int j = i; j < n.size(); j++) {
            swap(n[i], n[j]);
            perm(n, i+1);
            swap(n[i], n[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0);
        return ans;
    }
};