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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        
        int leftvalue = 0 , rightvalue;
        // leftvalue = sumOfLeftLeaves(root->left);
        if (root->left && root->left->left == NULL &&　root->left->right == NULL) {
            leftvalue = root->left->val;
        }
        // rightvalue = sumOfLeftLeaves(root->right);
        return leftvalue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        
    }
};