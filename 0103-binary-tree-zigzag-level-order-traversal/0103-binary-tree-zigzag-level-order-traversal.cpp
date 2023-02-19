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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> temp;

        while (!que.empty()) {
            temp.clear();
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                temp.push_back(cur->val);
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right); 

            }
            ans.push_back(temp);
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};