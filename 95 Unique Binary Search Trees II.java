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
     * @paramn n: An integer
     * @return: A list of root
     */
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<TreeNode>();
        }
        return generate(1, n);
    }

    private ArrayList<TreeNode> generate(int s, int t) {
        ArrayList<TreeNode> nodeList = new ArrayList<TreeNode>();
        if (s > t) {
            nodeList.add(null);
            return nodeList;
        }
        for (int i = s; i <= t; ++i) {
            ArrayList<TreeNode> leftNodeList = generate(s, i - 1);
            ArrayList<TreeNode> rightNodeList = generate(i + 1, t);
            for (TreeNode leftNode : leftNodeList) {
                for (TreeNode rightNode : rightNodeList) {
                    TreeNode node = new TreeNode(i);
                    node.left = leftNode;
                    node.right = rightNode;
                    nodeList.add(node);
                }
            }
        }
        return nodeList;
    }
}
