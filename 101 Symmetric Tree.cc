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
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
      return true;
    }
    return isSymmetricTree(root->left, root->right);
  }
  
 private:
  bool isSymmetricTree(TreeNode *p, TreeNode *q) {
    if (p == NULL) {
      return q == NULL;
    } else if (q == NULL) {
      return p == NULL;
    }
    return (p->val == q->val) && (isSymmetricTree(p->left, q->right)) &&
           (isSymmetricTree(p->right, q->left));
  }
};
