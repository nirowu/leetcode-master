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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        TreeNode* node;
        if (root->left){
            node = root->left;
            while (node->right) {
                node = node ->right;
            }
            if (node->val >= root->val) return false;
            
        }
        if (root->right) {
            node = root->right;
            while(node->left) {
                node = node->left;  
            }
            if (node->val <= root->val)  return false;
            
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};