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
        int size, maxi;
        if(root == NULL) return ans;
        que.push(root);
        while (!que.empty()) {
            size = que.size();
            maxi = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                maxi = max(cur->val, maxi);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};