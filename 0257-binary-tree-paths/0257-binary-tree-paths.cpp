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
    void Traversal(TreeNode* cur, vector<int>& path, vector<string>& ret) {
        if(cur == NULL) return;
        path.push_back(cur->val);
        if(cur->left == NULL && cur->right == NULL) {
            string spath;
            for (int i =0 ; i < path.size() - 1; i++) {
                spath += (to_string(path[i]));
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            ret.push_back(spath);
            return;
        }
        if (cur->left){
            Traversal(cur->left, path, ret);
            path.pop_back();            
        }
        if (cur->right) {
            Traversal(cur->right, path, ret);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> path;
        if (root == NULL) return ret;
        Traversal(root, path, ret);
        return ret;
    }
};