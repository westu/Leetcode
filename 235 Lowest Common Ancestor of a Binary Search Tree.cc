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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      int min_val = min(p->val, q->val);
      int max_val = max(p->val, q->val);
      if (min_val <= root->val && max_val >= root->val ||
          min_val == root->val || max_val == root->val) {
        return root;
      }
      if (max_val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
      } else {
        return lowestCommonAncestor(root->right, p, q);
      }
    }
};
