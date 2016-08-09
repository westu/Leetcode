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
 
class Ser {
public:
    int val;
    bool is_null;
    Ser(int x, bool null) : val(x), is_null(null) {}
};

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        if (root == NULL) {
            return "[]";
        }
        
        vector<Ser> ser_list;
        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        while (!bfs_queue.empty()) {
            TreeNode* node = bfs_queue.front();
            bfs_queue.pop();
            
            if (node == NULL) {
                ser_list.push_back(Ser(0, true));
            } else {
                ser_list.push_back(Ser(node->val, false));
            }
            
            if (node != NULL) {
                bfs_queue.push(node->left);
                bfs_queue.push(node->right);
            }
        }
        
        while (ser_list.back().is_null) {
            ser_list.pop_back();
        }
        string ans = "[";
        for (Ser ser : ser_list) {
            if (ser.is_null) {
                ans.append("null,");
            } else {
                ans.append(to_string(ser.val));
                ans.push_back(',');
            }
        }
        ans.pop_back();  // last ','
        ans.push_back(']');
        return ans;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        if (data == "[]") {
            return NULL;
        }
        int l(static_cast<int>(data.size())), i(1);
        vector<Ser> ser_list;
        while (i < l) {
            if (data.at(i) == 'n') {
                ser_list.push_back(Ser(0, true));
                i = i + 5;  // "null,"
            } else {
                int num(0);
                int start_i = i;
                while (data.at(i) != ',' && data.at(i) != ']') {
                    ++i;
                }
                ser_list.push_back(Ser(stoi(data.substr(start_i, i - start_i)), false));
                ++i;
            }
        }
        
        l = static_cast<int>(ser_list.size());
        vector<TreeNode*> node_list;
        node_list.push_back(new TreeNode(ser_list.at(0).val));
        i = 0;
        for (int j = 1; j < l; j += 2) {
            if (!ser_list.at(j).is_null) {
                TreeNode* tmp_node = new TreeNode(ser_list.at(j).val);
                node_list.at(i)->left = tmp_node;
                node_list.push_back(tmp_node);
            }
            
            if (j + 1 < l && !ser_list.at(j + 1).is_null) {
                TreeNode* tmp_node = new TreeNode(ser_list.at(j + 1).val);
                node_list.at(i)->right = tmp_node;
                node_list.push_back(tmp_node);
            }
            
            ++i;
        }
        return node_list.at(0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
