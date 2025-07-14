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
        if (!head || !head->next) return head;
        ListNode* cur = head;
        int arr[10005], idx = 0, size;
        while(cur) {
            arr[idx++] = cur->val;
            cur = cur->next;
        }
        size = idx--; idx = 0;
        int newarr[10005];
        for (int i = 0; i < size; i+=2) {
            newarr[idx++] = arr[i];
        }
        for (int i = 1; i < size; i+=2) {
            newarr[idx++] = arr[i];
        }
        for (int i = 0; i < size; i++) {
            cout<< newarr[i]<<" ";
        }
        idx = 0; cur = head;
        while(idx <= size) {
            cur->val = newarr[idx++];
            if (!cur->next) break;
            cur = cur->next;
        }
        return head;
    }
};