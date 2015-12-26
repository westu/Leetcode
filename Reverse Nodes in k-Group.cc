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
    bool has_k_nodes(ListNode* p, int k) {
        for (int i = 0; i < k; i++) {
            if (p == NULL) {
                return false;
            }
            p = p->next;
        }
        return true;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        while (has_k_nodes(p->next, k)) {
            vector<ListNode*> k_nodes;
            ListNode* tmp = p->next;
            for (int i = 0; i <= k; i++) {
                k_nodes.push_back(tmp);
                if (tmp != NULL) {
                    tmp = tmp->next;
                }
            }
            for (int i = k - 1; i >= 0; i--) {
                p->next = k_nodes[i];
                p = p->next;
            }
            p->next = k_nodes[k];
        }
        return head->next;
    }
};
