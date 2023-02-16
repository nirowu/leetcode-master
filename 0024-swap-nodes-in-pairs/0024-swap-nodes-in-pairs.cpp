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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while (cur->next != nullptr &&　cur->next->next != nullptr) {
            
            ListNode* temp = cur->next;
            // ListNode* temp1 = cur->next->next;
            ListNode* temp2 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = temp;
            cur->next->next->next = temp2;
            
            cur = cur->next->next;
            
        }
        return dummyhead->next;
    }
};