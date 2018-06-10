class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return true;
        }
        preorder += ',';  // symbol of ending
        vector<string> nodes;
        string node = "";
        for (int i = 0, j = 0; i < static_cast<int>(preorder.size()); ++j) {
            if (preorder.at(j) == ',') {
                nodes.push_back(node);
                node = "";
                i = j + 1;
            } else {
                node += preorder.at(j);
            }
        }
        int node_index = 0;
        return is_preorder(nodes, node_index) && node_index == nodes.size();  // every node is used
    }

private:
    bool is_preorder(const vector<string> &nodes, int &node_index) {
        if (node_index >= nodes.size()) {  // need a node here as a left/right child but thers is none
            return false;
        }
        if (nodes.at(node_index) == "#") {
            ++node_index;
            return true;
        }
        
        ++node_index;  // root of this subtree
        if (is_preorder(nodes, node_index) && is_preorder(nodes, node_index)) {  // left child & right child
            return true;
        } else {
            return false;
        }
    }
};
