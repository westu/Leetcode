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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return treeDepth(root) > -1 ? true : false;
    }

private:
    int treeDepth(TreeNode *root) {
        // return -1 means this tree is not balanced
        if (root == NULL) {
            return 0;
        }
        int left_depth = treeDepth(root -> left);
        int right_depth = treeDepth(root -> right);
        if (left_depth == -1 || right_depth == -1
            || abs(left_depth - right_depth) > 1) {
            return -1;
        } else {
            return max(left_depth, right_depth) + 1;
        }
    }
};
