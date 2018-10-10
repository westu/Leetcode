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
  void flatten(TreeNode* root) {
    if (root == NULL) {
      return;
    }
    while (root) {
      if (root->left) {
        TreeNode *tmp_node = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode *node = root->right;
        while (node->right != NULL) {
          node = node->right;
        }
        node->right = tmp_node;
      }
      root = root->right;
    }
  }
};
