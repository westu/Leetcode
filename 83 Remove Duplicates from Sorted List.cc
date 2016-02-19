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
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ans(head);
        while (head != NULL && head->next != NULL) {
            if (head->val != head->next->val) {
                head = head->next;
            } else {
                ListNode *tmp(head->next);
                head->next = head->next->next;
                delete tmp;
            }
        }
        return ans;
    }
};
