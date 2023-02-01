/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> que;
        Node *cur, *head;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<Node*> link(size);
            for (int i = 0; i < size; i++) {
                cur = que.front();
                que.pop();
                link[i] = cur;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            for (int i = 1; i < size; i++) {
                link[i - 1]->next = link[i];
            }
        }
        return root;
    }
};