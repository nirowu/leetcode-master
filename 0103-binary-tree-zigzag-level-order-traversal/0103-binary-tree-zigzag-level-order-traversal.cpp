class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> temp;
        int level = 1;
        while (!que.empty()) {
            int size = que.size();
            temp.resize(size);
            int left = 0, right = size-1;
            
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                if (level % 2) {
                    temp[left++] = cur->val;
                }
                else {
                    temp[right--] = cur->val;
                }
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right); 

            }
            ans.push_back(temp);
            level ++;
        }
        return ans;
    }
};