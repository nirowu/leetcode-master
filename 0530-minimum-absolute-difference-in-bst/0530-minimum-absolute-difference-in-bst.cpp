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
    void traversal(vector<int>& arr, TreeNode* cur) {
        if (cur == NULL) return;
        if (cur->left) traversal(arr, cur->left);
        arr.push_back(cur->val);
        if (cur->right) traversal(arr, cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        traversal(arr, root);
        int mini = INT_MAX;
        for (int i = 0; i < arr.size() -1; i++) {
            mini = min(mini, arr[i+1] - arr[i]);
        }
        return mini;
    }
};