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
    bool has_prev(false);
    int res(INT_MAX), prev;
    dfs (root, has_prev, res, prev);
    
    return res;
  }

 private:
  void dfs(TreeNode *root, bool &has_prev, int &res, int &prev) {
    if (root == NULL) {
      return;
    }
    dfs(root->left, has_prev, res, prev);
    if (!has_prev) {
      prev = root->val;
      has_prev = true;
    } else {
      res = min(res, root->val - prev);
      prev = root->val;
    }
    dfs(root->right, has_prev, res, prev);
  }
};
