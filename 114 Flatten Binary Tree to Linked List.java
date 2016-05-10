/**
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        TreeNode head = root;
        dfsFlatten(head, null);
    }

    private void dfsFlatten(TreeNode head, TreeNode node) {
        if (head == null) {
            return;
        }
        if (head.right != null) {
            dfsFlatten(head.right, node);
            node = head.right;
            if (head.left != null) {
                head.right = head.left;
                head.left = null;
                dfsFlatten(head.right, node);
            }
        } else {
            if (head.left == null) {
                if (node != null) {
                    head.right = node;
                    node = null;
                }
            } else {
                head.right = head.left;
                head.left = null;
                dfsFlatten(head.right, node);
            }
        }
    }
}
