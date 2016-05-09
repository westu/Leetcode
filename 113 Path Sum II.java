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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        LinkedList<Integer> path = new LinkedList<>();
        dfs(root, sum, 0, path, ans);
        return ans;
    }

    private void dfs(TreeNode root, int sum, int pathSum, LinkedList<Integer> path,
        List<List<Integer>> ans) {
        if (root == null) {
            return;
        }
        path.add(root.val);
        pathSum = pathSum + root.val;
        if (root.left == null && root.right == null && pathSum == sum) {
            ans.add(new LinkedList<Integer>(path));
        }
        dfs(root.left, sum, pathSum, path, ans);
        dfs(root.right, sum, pathSum, path, ans);
        path.removeLast();
    }
}
