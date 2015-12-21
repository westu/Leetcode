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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        ListNode* del = head;
        for (int i = 1; i < n; i++) {
            end = end->next;
        }
        ListNode* prev = del;
        while (end->next != NULL) {
            end = end->next;
            prev = del;
            del = del->next;
        }
        prev->next = del->next;
        if (del == head) {
            head = del->next;
        }
        delete del;
        return head;
    }
};
