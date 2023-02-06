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
    vector<vector<int>> res;
    vector<int> path;
    
    void Traversal(TreeNode*cur, int cnt) {
        if (cur == NULL) return;

        if (cur->left) {
            // cout<<cur->left->val<<" "<<cnt <<endl;
            path.push_back(cur->left->val);
            Traversal(cur->left, cnt - cur->left->val);
            path.pop_back();
        }
        if (cur->right) {
            // cout<<cur->right->val<<" "<< cnt <<endl;
            path.push_back(cur->right->val);
            Traversal(cur->right, cnt - cur->right->val);
            path.pop_back();
        }

        if (!cur->left && !cur->right && cnt == 0) {
            res.push_back(path);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return res;
        path.push_back(root->val);
        Traversal (root, targetSum - root->val);
        return res;
    }
};