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
     * @return: Inorder in ArrayList which contains node values.
     */
    
    /**
     * Solution 1:
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<TreeNode>();
        if (root == null) {
            return ans;
        }
        while (root != null || st.empty() == false) {
            while (root != null) {
                st.push(root);
                root = root.left;
            }
            root = st.peek();
            ans.add(root.val);
            st.pop();
            root = root.right;
        }
        return ans;
    }
     */
    
    // Solution 2:
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if (root == null) {
            return ans;
        }
        Stack st = new Stack();
        st.push(new DfsStatus(root));
        while (st.empty() == false) {
            DfsStatus tmp = (DfsStatus)st.peek();
            if (tmp.status == 0) {
                if (tmp.node.left != null) {
                    st.push(new DfsStatus(tmp.node.left));
                }
                tmp.status = 1;
            } else if (tmp.status == 1) {
                ans.add(tmp.node.val);
                if (tmp.node.right != null) {
                    st.push(new DfsStatus(tmp.node.right));
                }
                tmp.status = 2;
            } else {
                st.pop();
            }
        }
        return ans;
    }

    private class DfsStatus {
        TreeNode node;
        int status;
        // 0: leftNode not in stack; 1: leftNode in stack, rightNode not in stack;
        // 2: leftNode & rightNode in stack.
        DfsStatus(TreeNode node) {
            this.node = node;
            status = 0;
        }
    }
}
