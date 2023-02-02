class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            int size = que.size();
            ans += size;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return ans;
    }
};