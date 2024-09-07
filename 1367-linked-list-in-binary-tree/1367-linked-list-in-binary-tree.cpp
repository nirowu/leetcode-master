class Solution {
public:
    bool dfs(TreeNode* root, ListNode* cur) {
        if (!cur) return true;     
        if (!root) return false;   

        if (root->val == cur->val) {
            return dfs(root->left, cur->next) || dfs(root->right, cur->next);
        }
        
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; 

        return dfs(root, head) || isSubPath(head, root->left) ||                                                    isSubPath(head, root->right);
    }
};
