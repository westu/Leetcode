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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int ans(0);
        dfs(root, false, ans);
        return ans;
    }

private:
    void dfs(TreeNode *node, bool is_left, int &ans) {
        if (node->left == NULL && node->right == NULL && is_left) {
            ans += node->val;
        }
        if (node ->left != NULL) {
            dfs(node->left, true, ans);
        }
        if (node->right != NULL) {
            dfs(node->right, false, ans);
        }
    }
};
