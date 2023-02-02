ver1 bfs
```
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
```
ver2 dfs
```
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
```
​
`