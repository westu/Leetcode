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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
 public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > ans;
    if (root == NULL) {
      return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> ans_line;
    while (q.empty() == false) {
      TreeNode *tmp_node = q.front();
      q.pop();
      if (tmp_node == NULL) {
        ans.push_back(ans_line);
        ans_line.clear();
        if (q.empty() == false) {  // a new line in queue
          q.push(NULL);
        }
      } else {
        ans_line.push_back(tmp_node->val);
        if (tmp_node->left != NULL) {
          q.push(tmp_node->left);
        }
        if (tmp_node->right != NULL) {
          q.push(tmp_node->right);
        }
      }
    }
    return ans;
  }
};
