/**
 * Definition for singly-linked list.
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode 
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        int stepsA = 0;
        int stepsB = 0;
        ListNode n0 = headA;
        ListNode n1 = headB;
        while (n0.next != null) {
            ++stepsA;
            n0 = n0.next;
        }
        while (n1.next != null) {
            ++stepsB;
            n1 = n1.next;
        }
        if (n0 != n1) {
            return null;
        }
        n0 = headA;
        n1 = headB;
        for (int i = 0; i < Math.abs(stepsA - stepsB); ++i) {
            if (stepsA > stepsB) {
                n0 = n0.next;
            } else {
                n1 = n1.next;
            }
        }
        while (n0 != n1) {
            n0 = n0.next;
            n1 = n1.next;
        }
        return n0;
    }  
}
