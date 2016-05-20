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
     * @return: Preorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if (root == null) {
            return ans;
        }
        Stack<DfsStatus> stack = new Stack<DfsStatus>();
        stack.push(new DfsStatus(root, 0));
        while (!stack.empty()) {
            DfsStatus status = stack.peek();
            if (status.status == 0) {
                ans.add(status.node.val);
                ++status.status;
            } else if (status.status == 1) {
                ++status.status;
                if (status.node.left != null) {
                    stack.push(new DfsStatus(status.node.left, 0));
                }
            } else if (status.status == 2) {
                ++status.status;
                if (status.node.right != null) {
                    stack.push(new DfsStatus(status.node.right, 0));
                }
            } else {
                stack.pop();
            }
        }
        return ans;
    }

    private class DfsStatus {
        TreeNode node;
        int status;
        DfsStatus(TreeNode node, int status) {
            this.node = node;
            this.status = status;
        }
    }
}
