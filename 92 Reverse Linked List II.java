/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param ListNode head is the head of the linked list 
     * @oaram m and n
     * @return: The head of the reversed ListNode
     */
    public ListNode reverseBetween(ListNode head, int m , int n) {
        if (head == null || m == n) {
            return head;
        }
        ListNode ans = new ListNode(0);
        ans.next = head;
        head = ans;
        for (int i = 0; i < m - 1; ++i) {
            head = head.next;
        }
        ListNode tmp = head.next;
        ListNode tmpNext = tmp.next;
        ListNode tmpNextNext = tmpNext.next;
        for (int i = m; i < n; ++i) {
            tmpNext.next = tmp;
            tmp = tmpNext;
            tmpNext = tmpNextNext;
            if (i < n - 1) {  // the loop will go on
                tmpNextNext = tmpNextNext.next;
            }
        }
        head.next.next = tmpNext;
        head.next = tmp;
        return ans.next;
    }
}
