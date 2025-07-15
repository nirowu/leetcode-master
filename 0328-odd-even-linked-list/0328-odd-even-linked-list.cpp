class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;

        ListNode* oddhead = head;
        ListNode* evenhead = head->next;
        ListNode* odd = oddhead;
        ListNode* even = evenhead;

        int idx = 1;
        ListNode* cur = head->next->next;
        int oddnum = 0, evennum = 0;
        while (cur) {
            if (idx % 2) {
                odd->next = cur;
                odd = odd->next;
                oddnum++;
            } else {
                even->next = cur;
                even = even->next;
                evennum++;
            }
            idx++;
            if (!cur->next) break;
            cur = cur->next;
        }
        even->next = nullptr;
        odd->next = evenhead;
        return oddhead;
    }
};
