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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        return buildTree(nums, 0, nums.length - 1);
    }

    private TreeNode buildTree(int[] nums, int startPos, int endPos) {
        if (startPos > endPos) {
            return null;
        }
        int mid = startPos + (endPos - startPos) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = buildTree(nums, startPos, mid - 1);
        root.right = buildTree(nums, mid + 1, endPos);
        return root;
    }
}
