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
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null;
        }
        int len = getListLength(head);
        return buildTree(head, 0, len - 1);
    }

    private TreeNode buildTree(ListNode head, int startPos, int endPos) {
        if (startPos > endPos) {
            return null;
        }
        ListNode midNode = head;
        int midPos = startPos + (endPos - startPos) / 2;
        for (int i = startPos; i < midPos; ++i) {
            midNode = midNode.next;
        }
        TreeNode root = new TreeNode(midNode.val);
        root.left = buildTree(head, startPos, midPos - 1);
        root.right = buildTree(midNode.next, midPos + 1, endPos);
        return root;
    }

    private int getListLength(ListNode head) {
        int l = 0;
        while (head != null) {
            ++l;
            head = head.next;
        }
        return l;
    }
}
