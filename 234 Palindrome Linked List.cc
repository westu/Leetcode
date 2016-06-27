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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
if (head == NULL || head->next == NULL) {
            return true;
        }
        int l = get_length(head);
        ListNode* tailer = head;
        ListNode* tailer2 = tailer;
        for (int i = 0; i < l / 2; ++i) {
            tailer2 = tailer;
            tailer =  tailer->next;
        }
        tailer2->next = NULL;
        tailer2 = tailer;
        tailer = tailer->next;
        while (tailer != NULL) {
            ListNode* tmp = tailer->next;
            tailer->next = tailer2;
            tailer2 = tailer;
            tailer = tmp;
        }
        tailer = tailer2;
        while (head != NULL && tailer != NULL) {
            if (head->val != tailer->val) {
                return false;
            }
            head = head->next;
            tailer = tailer->next;
        }
        return true;
    }

private:
    int get_length(ListNode* head) {
        int l = 0;
        while (head != NULL) {
            ++l;
            head = head->next;
        }
        return l;
    }
};
