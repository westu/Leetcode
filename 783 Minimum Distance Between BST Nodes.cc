/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int minDiffInBST(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    bool has_prev(false);
    int prev, min_diff(-1);  // min_diff should be greater than 0
    in_order(root, has_prev, prev, min_diff);
    return min_diff;
  }

 private:
  void in_order(TreeNode *node, bool &has_prev, int &prev, int &min_diff) {
    if (node == NULL) {
      return;
    }
    in_order(node->left, has_prev, prev, min_diff);
    if (has_prev) {
      min_diff = min_diff == -1 ? node->val - prev : min(min_diff, node->val - prev);
    }
    has_prev = true;
    prev = node->val;
    in_order(node->right, has_prev, prev, min_diff);
  }
};
