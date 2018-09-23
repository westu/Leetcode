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
   * @param root: the root
   * @return: the minimum absolute difference between values of any two nodes
   */
  int getMinimumDifference(TreeNode * root) {
    if (root == NULL) {
      return 0;
    }

    stack<TreeNode *> traversal;
    bool has_prev(false);
    int res(INT_MAX), prev;
    TreeNode *node = root;
    while (node != NULL || !traversal.empty()) {  // stack empty checking for line 41
      while (node != NULL) {
        traversal.push(node);
        node = node->left;
      }
      node = traversal.top();
      traversal.pop();
      if (has_prev) {
        res = min(res, node->val - prev);
      }
      has_prev = true;
      prev = node->val;
      node = node->right;
    }
    return res;
  }
};
