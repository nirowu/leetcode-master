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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*> que;
        double sum = 0;
        if (root == NULL) return ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                sum += (double)cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back((sum / (double)size));
        }
        return ans;
    }
};