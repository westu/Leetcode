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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next  == NULL) {
            return head;
        }
        
        ListNode *odd_ptr = new ListNode(0);
        ListNode *odd_ptr2 = odd_ptr;
        ListNode *even_ptr = new ListNode(0);
        ListNode *even_ptr2 = even_ptr;
        while (head != NULL) {
            odd_ptr2->next = head;
            odd_ptr2 = odd_ptr2->next;
            
            head = head->next;
            if (head != NULL) {
                even_ptr2->next = head;
                even_ptr2 = even_ptr2->next;
                head = head->next;
            }
        }
        odd_ptr2->next = even_ptr->next;
        even_ptr2->next = NULL;
        
        return odd_ptr->next;
    }
};
