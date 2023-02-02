class Solution {
public:
    int Traversal(TreeNode* cur) {
        if (cur == NULL) return 0; 
        int left = 0, right = 0;
        if(cur->left) left = Traversal(cur->left);
        if(cur->right) right = Traversal(cur->right);
        return left + right + 1;
    }
    int countNodes(TreeNode* root) {
        return Traversal(root);
    }
};