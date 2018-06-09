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
    vector<int> findMode(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        int max_count = 0;
        int count = 0;
        TreeNode *pre = NULL;
        // dfs(root, pre, count, max_count, ans);
        
        stack<TreeNode*> trace;
        TreeNode *p = root;
        while (!trace.empty() || p) {
            while (p != NULL) {
                trace.push(p);
                p = p->left;
            }
            p = trace.top();
            trace.pop();
            
            if (pre != NULL && p->val == pre->val) {
                ++count;
            } else {
                count = 1;
            }
            if (count >= max_count) {
                if (count > max_count) {
                    max_count = count;
                    ans.clear();
                }
                ans.push_back(p->val);
            }
            
            pre = p;
            p = p->right;
        }
        return ans;
    }

private:
    void dfs(TreeNode *node, TreeNode *&pre, int &count, int &max_count, vector<int> &ans) {
        if (node == NULL) {
            return;
        }
        dfs(node->left, pre, count, max_count, ans);
        if (pre != NULL && node->val == pre->val) {
            ++count;
        } else {
            count = 1;
        }
        if (count >= max_count) {
            if (count > max_count) {
                ans.clear();
                max_count = count;
            }
            ans.push_back(node->val);
        }
        pre = node;
        dfs(node->right, pre, count, max_count, ans);
    }

};
