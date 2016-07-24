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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) {
            return ans;
        }
        dfs(ans, root, "");
        return ans;
    }

private:
    void dfs(vector<string>& ans, const TreeNode *node, string path) {
        path.append(to_string(node->val));
        
        if (is_child(node)) {
            ans.push_back(path);
            return;
        } else {
            path.append("->");
            if (node->left != NULL) {
                dfs(ans, node->left, path);
            }
            if (node->right != NULL) {
                dfs(ans, node->right, path);
            }
        }
    }

    bool is_child(const TreeNode *node) {
        return node->left == NULL && node->right == NULL;
    }
};
