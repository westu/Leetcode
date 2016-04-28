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
     * @return: ListNode head of the linked list
     */
    public static ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode dummyNode = new ListNode(0);
        ListNode assistNode = dummyNode;
        Integer lastNum = null;
        if (checkValEqual(head, head.next) == false) {
            assistNode.next = head;
            head = head.next;
            assistNode.next.next = null;
            assistNode = assistNode.next;
        }
        while (head != null) {
            if ((lastNum == null || head.val != lastNum.intValue())
                && checkValEqual(head, head.next) == false) {
                assistNode.next = head;
                lastNum = new Integer(head.val);
                head = head.next;
                assistNode.next.next = null;
                assistNode = assistNode.next;
            } else {
                lastNum = new Integer(head.val);
                head = head.next;
            }
        }
        return dummyNode.next;
    }

    private static boolean checkValEqual(ListNode firstNode, ListNode secondNode) {
        if (firstNode == null || secondNode == null) {
            return false;
        }
        return firstNode.val == secondNode.val;
    }
}
