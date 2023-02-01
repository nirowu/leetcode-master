# 0104
用queue的方式可以解但蠻慢的
可以用recursive的比較快
​
ver1
```
class Solution {
public:
int maxDepth(TreeNode* root) {
if (root == NULL) return 0;
queue<TreeNode*> que;
que.push(root);
int level = 0;
while (!que.empty()) {
int size = que.size();
for (int i = 0; i < size; i++) {
TreeNode* cur = que.front();
que.pop();
if(cur->left) que.push(cur->left);
if(cur->right) que.push(cur->right);
}
level++;
}
return level;
}
};
```
​
​