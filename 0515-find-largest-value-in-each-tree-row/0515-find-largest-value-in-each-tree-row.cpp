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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        if(root == NULL) return ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            TreeNode* peak = que.front();
            int maxi = peak->val;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                maxi = cur->val > maxi? cur->val: maxi; 
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};