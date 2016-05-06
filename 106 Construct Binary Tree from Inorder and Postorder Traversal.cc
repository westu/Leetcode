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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(0);
        recursionBuildTree(root, inorder, 0, inorder.length, postorder, 0, postorder.length);
        return root;
    }

    private void recursionBuildTree(
        TreeNode root,
        int[] inorder,
        int inorderStartPos,
        int inorderEndPos,
        int[] postorder,
        int postorderStartPos,
        int postorderEndPos) {
        if (inorderStartPos >= inorderEndPos) {
            return;
        }
        root.val = postorder[postorderEndPos - 1];
        for (int i = inorderStartPos; i < inorderEndPos; ++i) {
            if (inorder[i] == postorder[postorderEndPos - 1]) {
                // [inorderStartPos, i) is left subtree
                // [i + 1, inorderEndPos) is right subtree
                if (i > inorderStartPos) {
                    root.left = new TreeNode(0);
                    recursionBuildTree(
                        root.left,
                        inorder,
                        inorderStartPos,
                        i,
                        postorder,
                        postorderStartPos,
                        postorderStartPos + (i - inorderStartPos));
                }
                if (i < inorderEndPos - 1) {
                    root.right = new TreeNode(1);
                    recursionBuildTree(
                        root.right,
                        inorder,
                        i + 1,
                        inorderEndPos,
                        postorder,
                        postorderStartPos + (i - inorderStartPos),
                        postorderEndPos - 1);
                }
                break;
            }
        }
    }
}
