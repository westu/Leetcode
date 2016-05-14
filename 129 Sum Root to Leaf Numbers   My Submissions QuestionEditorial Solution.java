/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int sum = 0;

    public int sumNumbers(TreeNode root) {
        if (root == null) {
            return sum;
        }
        dfs(root, 0);
        return sum;
    }

    private void dfs(TreeNode node, int num) {
        num = num * 10 + node.val;
        if (node.left == null && node.right == null) {
            sum = sum + num;
            return;
        }
        if (node.left != null) {
            dfs(node.left, num);
        }
        if (node.right != null) {
            dfs(node.right, num);
        }
    }
}
