# 0226
兩種遞迴方法

```
TreeNode * temp = invertTree(root->right);
root->right = invertTree(root->left);
root->left = temp;
```

```
swap(root->left, root->right);
root->left = invertTree(root->left);
root->right = invertTree(root->right);
```
