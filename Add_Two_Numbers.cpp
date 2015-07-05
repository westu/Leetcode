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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int forward = 0;
        ListNode *head = l1;
        while (true) {
            l1->val = l1->val + l2->val + forward;
            forward = l1->val / 10;
            l1->val = l1->val % 10;
            if (l1->next == NULL || l2->next ==NULL) {
                break;
            }
            else {
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (l1->next == NULL) {
            l1->next = l2->next;
        }
        if (forward > 0) {
            while (l1->next != NULL) {
                l1 = l1->next;
                l1->val = l1->val + forward;
                forward = l1->val / 10;
                l1->val = l1->val % 10;
            }
            if (forward > 0) {
                l1->next = new ListNode(forward);
            }
        }
        return head;
    }
};
