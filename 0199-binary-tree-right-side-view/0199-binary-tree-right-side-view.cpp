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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        if(root == NULL) return ans;
        while (!que.empty()) {
            int size = que.size(), data = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                data = cur->val;
                // if (i == size - 1) ans.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back(data);
        }
        return ans;
    }
};