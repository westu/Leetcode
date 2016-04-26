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
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    public ListNode partition(ListNode head, int x) {
        if (head == null) {
            return null;
        }
        ListNode lessHead = new ListNode(0);
        // list of nodes which val is less than x
        ListNode greaterHead = new ListNode(0);
        // list of nodes which val is greater than or equal to x
        ListNode tmpNode = lessHead;
        ListNode tmpNode2 = greaterHead;
        while (head != null) {
            if (head.val < x) {
                tmpNode.next = head;
                tmpNode = tmpNode.next;
            } else {
                tmpNode2.next = head;
                tmpNode2 = tmpNode2.next;
            }
            head = head.next;
        }
        tmpNode.next = greaterHead.next;
        tmpNode2.next = null;
        // It may become a circle without this line, the last node .next maybe a node in the list
        return lessHead.next;
    }
}
