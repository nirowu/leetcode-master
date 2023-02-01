/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                Node *cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                for (int j = 0; j < cur->children.size(); j++) {
                    // if (cur->children[j]) 
                    que.push(cur->children[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};