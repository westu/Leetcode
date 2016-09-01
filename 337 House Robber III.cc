/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        pair<int, int> ans;
        ans = dfs(root);
        return max(ans.first, ans.second);
    }

private:
    pair<int, int> dfs(TreeNode *node) {  // first: rob this house; second: not rob this house
        if (node == NULL) {
            return make_pair(0, 0);
        }
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        return make_pair(node->val + left.second + right.second,
            max(left.first, left.second) + max(right.first, right.second));
    }
};
