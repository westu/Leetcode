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
    stack<TreeNode*> trace;
    while (root != NULL || !trace.empty()) {
      while (root) {
        trace.push(root);
        root = root->left;
      }
      TreeNode *node = trace.top();
      trace.pop();
      if (has_prev) {
        min_diff = min_diff == -1 ? node->val - prev : min(min_diff, node->val - prev);
      }
      has_prev = true;
      prev = node->val;
      root = node->right;
    }
    return min_diff;
  }
};
