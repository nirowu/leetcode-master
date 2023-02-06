class Solution {
public:
    int post_idx;
    TreeNode* utilBST(vector<int>& inorder, int is,int ie, vector<int>& postorder){
        if(is>ie)return NULL;
        TreeNode* root=new TreeNode(postorder[post_idx--]);
        int idx;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                idx=i;
                break;
            }
        }
        root->right=utilBST(inorder,idx+1,ie,postorder);
        root->left=utilBST(inorder,is,idx-1,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx=postorder.size()-1;
        return utilBST(inorder,0,inorder.size()-1,postorder);
        
    }
};