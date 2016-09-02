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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *tmp_head = new ListNode(0);
        ListNode *prev_node = tmp_head;
        tmp_head->next = head;
        while (head != NULL) {
            if (head->val == val) {
                prev_node->next = head->next;
                delete head;
                head = prev_node->next;
            } else {
                prev_node = head;
                head = head->next;
            }
        }
        return tmp_head->next;
    }
};
