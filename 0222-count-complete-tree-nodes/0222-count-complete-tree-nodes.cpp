class Solution {
public:
    int cnt(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftnum = cnt(cur->left);
        int rightnum = cnt(cur->right);
        
        return leftnum + rightnum + 1;
    }
    int countNodes(TreeNode* root) {
        return cnt(root);
    }
};