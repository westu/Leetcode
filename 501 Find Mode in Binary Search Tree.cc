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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        int max_count = 0;
        dfs(root, max_count, ans);
        return ans;
    }

private:
    void dfs(TreeNode *node, int &max_count, vector<int> &ans) {
        if (node == NULL) {
            return;
        }
        
        int count = dfs_count(node, node->val);
        if (count > max_count) {
            max_count = count;
            ans.clear();
            ans.push_back(node->val);
        } else if (count == max_count) {
            ans.push_back(node->val);
        }
        
        dfs(node->left, max_count, ans);
        dfs(node->right, max_count, ans);
    }
    
    int dfs_count(TreeNode *node, int val) {
        if (node == NULL) {
            return 0;
        }
        return dfs_count(node->left, val) + dfs_count(node->right, val) + (node->val == val);
    }
};
