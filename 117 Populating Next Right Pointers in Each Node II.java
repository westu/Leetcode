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
        if (root == null ||
            root.left == null && root.right == null) {
            return;
        }
        TreeLinkNode node = root;
        while (true) {
            TreeLinkNode nextLayerLeftestNode = null;
            TreeLinkNode prevNode = null;
            while (node != null) {
                if (node.left != null) {
                    if (nextLayerLeftestNode == null) {
                        nextLayerLeftestNode = node.left;
                    } else {
                        prevNode.next = node.left;
                    }
                    prevNode = node.left;
                }
                if (node.right != null) {
                    if (nextLayerLeftestNode == null) {
                        nextLayerLeftestNode = node.right;
                    } else {
                        prevNode.next = node.right;
                    }
                    prevNode = node.right;
                }
                node = node.next;
            }
            if (nextLayerLeftestNode == null) {
                break;
            } else {
                node = nextLayerLeftestNode;
            }
        }
    }
}
