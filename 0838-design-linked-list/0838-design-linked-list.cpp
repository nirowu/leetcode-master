/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {


public:
    struct Node {
        int val;
        Node* next;
        Node(int x): val(x), next(nullptr) {}
    };


    MyLinkedList() {
        size = 0;
        dummyhead = new Node(0);
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* tmp = dummyhead->next;
        while(index--) {
            tmp = tmp -> next;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode-> next = dummyhead->next;
        dummyhead-> next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if (size == 0) {
            dummyhead->next = newNode;
        } else {
            Node *tmp = dummyhead;
            while (tmp && tmp->next) {
                tmp = tmp->next;
            }
            tmp-> next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node *newNode = new Node(val);
        Node *tmp = dummyhead;
        while (index--) {
            tmp = tmp->next;
        }
        newNode-> next = tmp->next;
        tmp -> next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        Node *tmp = dummyhead;
        while (index--) {
            tmp = tmp->next;
        }
        Node* toDelete = tmp->next;
        tmp ->next = tmp->next->next;
        delete toDelete;
        size--;
    }

private:
    int size = 0;
    Node* dummyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

