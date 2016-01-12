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
  void recoverTree(TreeNode* root) {
    vector<pair<int, TreeNode*> > inorder_list;
    inorder_traversal(root, inorder_list);
    int w1(-1), w2(-1);
    for (int i = 0; i < static_cast<int>(inorder_list.size()); ++i) {
      if (w1 == -1 && i < static_cast<int>(inorder_list.size()) - 1 &&
          inorder_list.at(i).first > inorder_list.at(i + 1).first) {
        w1 = i;
      }
      if (i > 0 && inorder_list.at(i).first < inorder_list.at(i - 1).first) {
        w2 = i;
      }
    }
     int tmp = inorder_list.at(w1).second->val;
     inorder_list.at(w1).second->val = inorder_list.at(w2).second->val;
     inorder_list.at(w2).second->val = tmp;
  }

 private:
  void inorder_traversal(TreeNode* node, vector<pair<int, TreeNode*> >&
                                      inorder_list) {
    if (node->left != NULL) {
      inorder_traversal(node->left, inorder_list);
    }
    inorder_list.push_back(make_pair(node->val, node));
    if (node->right != NULL) {
      inorder_traversal(node->right, inorder_list);
    }
  }
};
