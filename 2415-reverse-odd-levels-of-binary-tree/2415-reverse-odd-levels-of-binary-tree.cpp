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
    int levelCnt;
    void helper(TreeNode* left, TreeNode* right, int levelCnt) {

        if (!left || !right) {
            return;
        }
        if (levelCnt%2) {
            swap (left->val, right->val);
        }

        helper(left->left, right->right, levelCnt+1);
        helper(left->right, right->left, levelCnt+1);

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, 1);
        return root;
    }
};