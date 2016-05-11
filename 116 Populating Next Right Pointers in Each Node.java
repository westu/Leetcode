/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null || root.left == null) {
            return;
        }
        TreeLinkNode node = root;
        while (node.left != null) {
            TreeLinkNode nextLayerFirstNode = node.left;
            while (true) {
                node.left.next = node.right;
                if (node.next != null) {
                    node.right.next = node.next.left;
                    node = node.next;
                } else {
                    node.right.next = null;
                    break;
                }
            }
            node = nextLayerFirstNode;
        }
    }
}
