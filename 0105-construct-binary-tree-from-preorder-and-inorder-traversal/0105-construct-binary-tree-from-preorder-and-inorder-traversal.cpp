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
    TreeNode* Traversal(vector<int>& preorder, int a, int b, vector<int>& inorder, int m, int n) {
        if (a > b) return NULL;
        TreeNode *root = new TreeNode(preorder[a]);
        int idx = mp[root->val]; 
        root->left = Traversal(preorder, a+1, a+idx-m, inorder, m, idx-1);
        root->right = Traversal(preorder, a+1+idx-m, b, inorder, idx+1, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i =0 ; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return Traversal(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};