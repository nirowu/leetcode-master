class MyLinkedList {

public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    
    MyLinkedList() {
        size = 0 ;
        dummyhead = new LinkedNode(0);
    }
    
    int get(int index) {
        if (index >= size) return -1;
        LinkedNode* cur = dummyhead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newHead = new LinkedNode(val);
        newHead->next = dummyhead->next; 
        dummyhead->next = newHead;
        size ++;
        // printLinkedList();
    }
    
    void addAtTail(int val) {
        LinkedNode* cur = dummyhead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        LinkedNode* newnode = new LinkedNode(val);
        cur->next = newnode;
        size ++;
        // printLinkedList();

    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) {
            index = 0;
            return;
        }
        if (index > size) return;
        LinkedNode* newnode = new LinkedNode(val);
        LinkedNode* cur = dummyhead;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        size ++;

    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        LinkedNode* cur = dummyhead;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size --;
        // printLinkedList();

    }
    // void printLinkedList() {
    //     LinkedNode* cur = dummyhead;
    //     while (cur->next != nullptr) {
    //         cout << cur->next->val << " ";
    //         cur = cur->next;
    //     }
    //     cout << endl;
    // }
private:
    int size;
    LinkedNode *dummyhead;
    
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