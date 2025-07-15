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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next; //the second list
        }
        ListNode* prev = nullptr;
        while(slow) {
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        ListNode* cur = head;
        while(cur) {
            if (cur->val != prev->val) {
                return false;
            }
            if (!cur->next || !prev->next) break;
            cur = cur->next; prev = prev->next;
        }
        return true;
    }
};