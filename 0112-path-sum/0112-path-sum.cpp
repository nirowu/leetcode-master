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
//     bool traversal(TreeNode* cur, int cnt) {
//         if (!cur->left && !cur->right && cnt == 0) return true; 
//         if (!cur->left && !cur->right) return false; 

//         if (cur->left) {
//             if (traversal(cur->left, cnt - cur->left->val)){
//                 return true;
//             }
//         }
//         if (cur->right) {
//             if (traversal(cur->right, cnt - cur->right->val)) {
//                 return true;
//             }
//         }
//         return false;
//     }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (!root->left && !root->right && targetSum == root->val){
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || 
                hasPathSum(root->right, targetSum - root->val);
    }
};