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
     * @return: An integer.
     */
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int depth = 1;
        return dfsMinDepth(root, depth);
    }

    private int dfsMinDepth(TreeNode node, int depth) {
        if (node.left == null && node.right == null) {
            return depth;
        } else if (node.left == null) {
            return dfsMinDepth(node.right, depth + 1);
        } else if (node.right == null) {
            return dfsMinDepth(node.left, depth + 1);
        } else {
            return Math.min(
                dfsMinDepth(node.left, depth + 1),
                dfsMinDepth(node.right, depth + 1));
        }
    }
}
