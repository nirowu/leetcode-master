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
    int ret = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        LongestPathToLeaf(root); 
        return ret;
    }
    
    int LongestPathToLeaf(TreeNode* node)
    {
        if (node == NULL) return 0;
        // cout<<"val:"<<node->val<<endl;
        int leftPath = LongestPathToLeaf(node->left);
        int rightPath = LongestPathToLeaf(node->right);
        // cout<<leftPath<<" ";
        // cout<<rightPath<<endl;

        ret = max(ret, leftPath+rightPath);
        return max(leftPath, rightPath) + 1;
    }
};