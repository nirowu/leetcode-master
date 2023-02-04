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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head ;
        int num = 0;
        while (cur) {
           num ++;
            cur = cur->next;
        }
        for (int i = 0; i < num / 2; i++){
            head = head->next; 
        }
        return head;
    }
};