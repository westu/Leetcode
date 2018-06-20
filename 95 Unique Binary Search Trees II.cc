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
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      vector<TreeNode*> nodes;
      return nodes;
    }
    return generateRange(1, n);
  }

private:
  vector<TreeNode*> generateRange(int start, int end) {
    vector<TreeNode*> nodes;
    if (start > end) {
      nodes.push_back(NULL);
    } else {
      for (int i = start; i <= end; ++i) {
        vector<TreeNode*> left_tree = generateRange(start, i - 1);
        vector<TreeNode*> right_tree = generateRange(i + 1, end);
        for (int j = 0; j < static_cast<int>(left_tree.size()); ++j) {
          for (int k = 0; k < static_cast<int>(right_tree.size()); ++k) {
            TreeNode *node = new TreeNode(i);
            node->left = left_tree.at(j);
            node->right = right_tree.at(k);
            nodes.push_back(node);
          }
        }
      }
    }
    return nodes;
  }
};
