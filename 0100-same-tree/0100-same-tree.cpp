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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        
        if (p == NULL && q == NULL) return true;
        // if (p == NULL || q == NULL) return false;
        queue<TreeNode*> que_p;
        queue<TreeNode*> que_q;
        que_p.push(p);
        que_q.push(q);

        while (!que_p.empty() && ! que_q.empty()) {
            if (que_p.size() != que_q.size() ) return false;
            
            for (int i = 0; i < que_p.size(); i++) {
                TreeNode* A = que_p.front();
                TreeNode* B = que_q.front();
                que_p.pop();
                que_q.pop();
                if(A != NULL && B != NULL){
                    if(A->val != B->val) return false;
                } 
                else if(A == NULL && B == NULL) {
                    continue;
                }
                else {
                    return false;
                }
                que_p.push(A->left);
                que_p.push(A->right);
                que_q.push(B->left);
                que_q.push(B->right);
            }
        }
        return true;
        
    }
};