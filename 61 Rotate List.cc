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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        int n = get_list_length(head);
        k %= n;
        ListNode *p1(head), *p2(head);
        // p1 = head;
        // p2 = head;
        for (int i = 0; i < k; ++i) {
            p1 = p1->next;
        }
        while (p1->next != NULL) {
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        return head;
    }

private:
    int get_list_length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            ++len;
        }
        return len;
    }
};
