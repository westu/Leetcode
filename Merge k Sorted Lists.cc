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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* tmp = new ListNode(0);
        ListNode* ans = tmp;
        multimap<int, int> p_heap;
        for (int i = 0; i < static_cast<int>(lists.size()); i++) {
            if (lists[i] != NULL) {
                p_heap.insert(make_pair(lists[i]->val, i));
            }
        }
        while (p_heap.size() > 0) {
            int min_index = (*p_heap.begin()).second;
            p_heap.erase(p_heap.begin());
            tmp->next = lists[min_index];
            tmp = tmp->next;
            if (lists[min_index]->next != NULL) {
                lists[min_index] = lists[min_index]->next;
                p_heap.insert(make_pair(lists[min_index]->val, min_index));
            }
        }
        return ans->next;
    }
};
