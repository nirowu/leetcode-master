/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int sizeA = 0, sizeB = 0, mini;
        while (curA) {
            curA = curA->next;
            sizeA++;
        }
        while (curB) {
            curB = curB->next;
            sizeB++;
        }
        mini = sizeA - sizeB;
        curA = headA, curB = headB;
        if (mini > 0) {
            while(mini--) {
                curA = curA->next;
            }
        }
        else {
            mini = -mini;
            while (mini--) {
                curB = curB->next;
            }
        }
        
        while (curA && curB) {
            if (curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
        
    }
};