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
    unordered_map<int, int> mp;
    unordered_map<int, int> ::iterator iter;

    int maxi = INT_MIN;
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        if (cur->left) traversal(cur->left);
        if (mp.find(cur->val) != mp.end()) mp[cur->val] ++;
        else mp[cur->val] = 1;
        maxi = max(maxi, mp[cur->val]);
        if (cur->right) traversal(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        vector<int> ans;
        for (iter = mp.begin(); iter != mp.end(); iter++) {
            if((*iter).second == maxi) {
                ans.push_back((*iter).first);
            }
        }
        return ans;
    }
};