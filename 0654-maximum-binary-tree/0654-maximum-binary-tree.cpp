/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* dfs(vector<int>&nums, int a, int b) {
        if (a > b) return NULL;
        int rootVal = nums[a];
        for (int i = a ; i <= b; i++) {
            rootVal = max(rootVal, nums[i]);
        }
        TreeNode* root = new TreeNode(rootVal);
        int pos = mp[rootVal];
        root->left = dfs(nums, a, pos-1);
        root->right = dfs(nums, pos+1, b);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        return dfs(nums, 0, nums.size()-1);
    }
};