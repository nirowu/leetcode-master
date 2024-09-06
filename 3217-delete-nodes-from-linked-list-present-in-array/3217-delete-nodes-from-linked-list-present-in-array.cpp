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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map <int, int> map;
        for (int i: nums) {
            map[i]++;
        }
        
        
        if (!head->next) {
            if (map[head->val]) return NULL;
            else return head;
        }
        ListNode *ptr1 = head;
        
        while (ptr1) {
            if (map[ptr1->val]) {
                ptr1 = ptr1 -> next;
            }
            else break;
        }

        ListNode* ptr2 = ptr1;
        ListNode* ptr3 = ptr1 -> next;

        while(ptr2 && ptr3) {
            if (ptr3->next) {
                if (map[ptr3->val]) {
                    ptr3 = ptr3->next;
                    ptr2->next = ptr3;
                }
                else {
                    ptr2 = ptr2->next;
                    ptr3 = ptr3->next;
                }
            }
            else {
                if (map[ptr3->val]) {;
                    ptr2->next = NULL;
                }
                break;
            }

        }
        return ptr1;
    }
};