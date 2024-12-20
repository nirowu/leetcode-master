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
    int arr[10005] = {0};
    int idx;
    void helper(TreeNode* node) {
        if (node->left) helper(node->left);
        arr[idx++] = node->val;
        if (node->right)helper(node->right);
    }
    bool isValidBST(TreeNode* root) {
        idx = 0;
        bool ans ;
        if (!root->left && !root->right) {
            return true;
        }
        helper(root);
        for (int i = 1; i < idx ;i++) {
            if(arr[i-1] >= arr[i]) {
                return false;
            }
        }
        return true;
    }
};