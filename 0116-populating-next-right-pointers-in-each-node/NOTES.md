# 0116
level order + 串起來
​
ver1
```
class Solution {
public:
Node* connect(Node* root) {
if(root == NULL) return root;
queue<Node*> que;
Node *cur, *head;
que.push(root);
while (!que.empty()) {
int size = que.size();
head = que.front();
for (int i = 0; i < size; i++) {
cur = que.front();
que.pop();
if(i != 0) head -> next = cur;
head = cur;
if (cur->left) que.push(cur->left);
if (cur->right) que.push(cur->right);
}
}
return root;
}
};
```
​
ver2
用vetor 先存起來在串