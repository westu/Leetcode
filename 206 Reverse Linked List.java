/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: The new head of reversed linked list.
     */
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode beforeNode = head;
        ListNode nextNode = head.next;
        head.next = null;
        while (nextNode != null) {
            ListNode nodeAfterNext = nextNode.next;
            nextNode.next = beforeNode;
            beforeNode = nextNode;
            nextNode = nodeAfterNext;
        }
        return beforeNode;
    }
}
