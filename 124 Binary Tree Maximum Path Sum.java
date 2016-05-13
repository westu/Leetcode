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
    private int ans = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int leftVal = dfs(node.left);
        int rightVal = dfs(node.right);
        int thisNodeVal = node.val
            + Math.max(leftVal, 0)
            + Math.max(rightVal, 0);
        ans = Math.max(ans, thisNodeVal);
        return node.val + Math.max(
            Math.max(leftVal, 0), Math.max(rightVal, 0));
    }
}
