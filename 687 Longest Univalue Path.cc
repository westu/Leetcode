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
    int longestUnivaluePath(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        dfs(root, -1, ans);
        return ans - 1;  // edges' number, not nodes' number
    }

private:
    int dfs(TreeNode *node, int pval, int &ans) {
        if (node == NULL) {
            return 0;
        }
        int left_len = dfs(node->left, node->val, ans);
        int right_len = dfs(node->right, node->val, ans);
        ans = max(ans, left_len + right_len + 1);
        if (node->val == pval) {
            return max(left_len, right_len) + 1;
        } else {
            return 0;
        }
    }
};
