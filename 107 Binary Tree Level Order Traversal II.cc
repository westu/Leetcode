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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> tmp_ans;
        while (q.empty() == false) {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL) {
                ans.push_back(tmp_ans);
                tmp_ans.clear();
                if (q.empty() == false) {
                    q.push(NULL);
                }
            } else {
                tmp_ans.push_back(node -> val);
                if (node -> left != NULL) {
                    q.push(node -> left);
                }
                if (node -> right != NULL) {
                    q.push(node -> right);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
