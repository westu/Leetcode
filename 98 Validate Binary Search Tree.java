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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        return lessThan(root.left, root)
               && greaterThan(root.right, root)
               && isValidBST(root.left)
               && isValidBST(root.right);
    }

    private boolean lessThan(TreeNode node1, TreeNode node2) {
        if (node1 == null) {
            return true;
        }
        while (node1.right != null) {
            node1 = node1.right;
        }
        return node1.val < node2.val;
    }

    private boolean greaterThan(TreeNode node1, TreeNode node2) {
        if (node1 == null) {
            return true;
        }
        while (node1.left != null) {
            node1 = node1.left;
        }
        return node1.val > node2.val;
    }
}
