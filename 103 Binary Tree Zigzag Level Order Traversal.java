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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        if (root == null) {
            return ans;
        }
        List<Stack> stackList = new ArrayList<Stack>();
        stackList.add(new Stack());
        stackList.add(new Stack());
        int index = 0;
        stackList.get(0).push(root);
        while (!stackList.get(index).empty()) {
            ArrayList<Integer> tmpAns = new ArrayList<Integer>();
            while (!stackList.get(index).empty()) {
                TreeNode node = (TreeNode) stackList.get(index).pop();
                tmpAns.add(node.val);
                if (index == 0) {
                    stack_push(stackList.get(1 - index), node.left, node.right);
                } else {
                    stack_push(stackList.get(1 - index), node.right, node.left);
                }
            }
            ans.add(tmpAns);
            index = 1 - index;
        }
        return ans;
    }

    private void stack_push(Stack st, TreeNode node1, TreeNode node2) {
        if (node1 != null) {
            st.push(node1);
        }
        if (node2 != null) {
            st.push(node2);
        }
    }
}
