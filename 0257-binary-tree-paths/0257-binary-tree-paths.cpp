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
    void Traversal(TreeNode* cur, string path, vector<string>& ret) {
        // if (cur == NULL) return;
        path += (to_string(cur->val));
        if (!cur->left && !cur->right) {
            ret.push_back(path);
            return;
        }
        if (cur->left){
            Traversal(cur->left, path + "->", ret);          
        }
        if (cur->right) {
            Traversal(cur->right, path + "->", ret);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;
        if (root == NULL) return ret;
        Traversal(root, path, ret);
        return ret;
    }
};