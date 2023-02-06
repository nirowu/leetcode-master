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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        
        int rootVal = postorder[postorder.size() - 1], i;
        TreeNode* root = new TreeNode(rootVal);
        for (i = 0; i < inorder.size(); i++) {  // i the delimiter of inorder list
            if (inorder[i]== rootVal )break;
        }
        
        vector<int> inorderLeft (inorder.begin(), inorder.begin() + i);
        vector<int> inorderRight (inorder.begin() + i + 1, inorder.end());

                
        postorder.pop_back();
        vector<int> postorderLeft (postorder.begin(), postorder.begin() + inorderLeft.size());
        vector<int> postorderRight (postorder.begin() + inorderLeft.size(), postorder.end());

        root->left = buildTree(inorderLeft, postorderLeft);
        root->right = buildTree(inorderRight, postorderRight);

                
        return root;
    }
};