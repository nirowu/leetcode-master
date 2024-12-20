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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* ptr = head;
        ListNode* ptr2 = head;

        int idx = 0;
        int cnt1 = 0, cnt2 = 0;
        int arr1[10005] = {0};
        int arr2[10005] = {0};

        while(ptr) {
            if (!(idx%2)) {
                arr1[cnt1++] = ptr->val; 
            }
            else {
                arr2[cnt2++] = ptr->val;
            }
            idx += 1;
            ptr = ptr->next;
        }
        for (int i = 0; i < cnt1; i++) {
            ptr2->val = arr1[i];
            ptr2 = ptr2->next;
        }
        for (int i = 0; i < cnt2; i++) {
            ptr2->val = arr2[i];
            ptr2 = ptr2->next;
        }

        return head;
    }
};