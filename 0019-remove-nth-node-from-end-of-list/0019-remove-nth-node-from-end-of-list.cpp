/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        map<int, int> mp;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        
        ListNode* cur = head;
        int idx = 0;
        while (cur) {
            mp[idx++] = cur->val;
            cur = cur->next;
        }
        cur = dummyhead;
        int delnode = idx - n;
        while (delnode--) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        
        
        return dummyhead->next;
        
        
    }
};