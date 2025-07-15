/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // copy a-a'-b-b'
        Node* cur = head;
        while(cur) {
            Node* copynode = new Node(cur->val);
            copynode->next = cur->next;
            cur->next = copynode;
            cur = copynode->next;
        }
        // cur = head;
        // while(cur) {
        //     cout<< cur->val<<" ";
        //     cur = cur->next;
        // }
        // add the random link to copy one
        cur = head;
        while(cur) {
            if (!cur->random) cur->next->random = nullptr;
            else{
                cur->next->random = cur->random->next;
            }
            if (!cur->next->next) break;
            cur = cur->next->next;
        }
        // cut the original
        cur = head; 
        Node *newhead = head->next;
        Node *newcur = newhead;
        while(cur && cur->next) {
            if (!cur->next->next) break;
            cur->next = newcur->next;
            newcur->next = cur->next->next;
            cur = cur->next;
            newcur = newcur->next;
        }
        cur->next = nullptr;
        // newcur->next = nullptr;
        return newhead;
    }
};