/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        dfs(root);
    }

private:
    void dfs(TreeNode *node) {
        if (node == NULL || node->left == NULL && node->right == NULL) {
            return;
        }
        TreeNode *tmp_node = node->left;
        node->left = node->right;
        node->right = tmp_node;
        dfs(node->left);
        dfs(node->right);
    }
};
