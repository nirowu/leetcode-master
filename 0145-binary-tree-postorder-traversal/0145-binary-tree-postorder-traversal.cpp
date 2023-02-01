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
    void Traversal(vector<int>&ans, TreeNode* cur) {
        if(cur == NULL) return;
        Traversal(ans, cur->left);
        Traversal(ans, cur->right);
        ans.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        Traversal(ans, root);
        return ans;
    }
};