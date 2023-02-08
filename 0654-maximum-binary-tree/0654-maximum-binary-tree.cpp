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
        int rootVal = INT_MIN, pos;
        for (int i = a ; i <= b; i++) {
            if (rootVal < nums[i]) {
                rootVal = nums[i];
                pos = i;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = dfs(nums, a, pos-1);
        root->right = dfs(nums, pos+1, b);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};