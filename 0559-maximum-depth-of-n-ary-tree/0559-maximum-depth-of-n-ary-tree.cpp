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
    int depth (Node* cur) {
        if (cur == NULL) return 0;
        int size = cur->children.size(), ret = 0;
        for (int i = 0; i < size; i++) {
            ret = max(depth(cur->children[i]), ret);
        }
        return ret + 1;
    }
    int maxDepth(Node* root) {
        return depth(root);
    }
};