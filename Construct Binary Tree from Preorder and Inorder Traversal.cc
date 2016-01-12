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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() == true) {
      return NULL;
    }
    TreeNode* root;
    int w = 0;
    dfs(root, preorder, w, inorder, 0, static_cast<int>(inorder.size()) - 1);
    return root;
  }

private:
  void dfs(TreeNode*& node, vector<int>& preorder, int& w, vector<int>& inorder,
                int s, int t) {
    node = new TreeNode(preorder.at(w));
    for (int i = s; i <= t; ++i) {
      if (inorder.at(i) == preorder.at(w)) {
        if (i > s) {
          ++w;
          dfs(node->left, preorder, w, inorder, s, i - 1);
        }
        if (i < t) {
          ++w;
          dfs(node->right, preorder, w, inorder, i + 1, t);
        }
        break;
      }
    }
  }
};
