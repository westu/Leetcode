/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool have_two_nodes(ListNode* ln) {
        if (ln == NULL || ln->next == NULL) {
            return false;
        } else {
            return true;
        }
    }
    
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* it = new ListNode(0);
        it->next = head;
        head = it;
        while (have_two_nodes(it->next) == true) {
            ListNode* tmp = it->next->next;
            it->next->next = tmp->next;
            tmp->next = it->next;
            it->next = tmp;
            it = it->next->next;
        }
        return head->next;
    }
};
