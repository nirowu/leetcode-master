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
        int num = 1;
        while (cur->next != NULL) {
            cur = cur->next;
            num ++;
        }
        num = num / 2;
        for (int i = 0; i < num; i++){
            head = head->next; 
        }
        return head;
    }
};