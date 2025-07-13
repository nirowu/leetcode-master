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
    ListNode* reverseList(ListNode* head) {
        int arr[5005], idx = 0;
        ListNode* cur = head;
        while(cur) {
            arr[idx++] = cur->val;
            cur = cur->next;
        }
        ListNode* rev = head;
        while(rev) {
            rev->val = arr[--idx];
            rev = rev->next;
        }
        return head;
    }
};