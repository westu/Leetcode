/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        push_stack(root);
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }
    
    void push_stack(TreeNode *node) {
        while (node != NULL) {
            path.push(node);
            node = node->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = path.top();
        if (path.top()->right != NULL) {
            path.pop();
            push_stack(node->right);
        } else {
            path.pop();
        }
        return node->val;
    }

private:
    stack<TreeNode*> path;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
