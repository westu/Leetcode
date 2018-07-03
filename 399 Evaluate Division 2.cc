class Solution {
 public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
      vector<double>& values,
      vector<pair<string, string>> queries) {
    for (int i = 0; i < static_cast<int>(equations.size()); ++i) {
      const string &n0 = equations.at(i).first;
      const string &n1 = equations.at(i).second;
      if (node_map_.find(n0) == node_map_.end() && node_map_.find(n1) == node_map_.end()) {
        Node *node0 = new Node();
        Node *node1 = new Node();
        node0->value = values.at(i);
        node1->parent = node0;
        node_map_[n0] = node0;
        node_map_[n1] = node1;
      } else if (node_map_.find(n0) == node_map_.end()) {
        Node *node = new Node();
        node->parent = node_map_[n1];
        node->value = node_map_[n1]->value * values.at(i);
        node_map_[n0] = node;
      } else if (node_map_.find(n1) == node_map_.end()) {
        Node *node = new Node();
        node->parent = node_map_[n0];
        node->value = node_map_[n0]->value / values.at(i);
        node_map_[n1] = node;
      } else {
        UnionSets(node_map_[n0], node_map_[n1], values.at(i));
      }
    }

    vector<double> ans;
    for (auto query : queries) {
      const string &q0 = query.first;
      const string &q1 = query.second;
      if (node_map_.find(q0) == node_map_.end() || node_map_.find(q1) == node_map_.end() ||
          FindParent(node_map_[q0]) != FindParent(node_map_[q1])) {
        ans.push_back(-1);
      } else {
        ans.push_back(node_map_[q0]->value / node_map_[q1]->value);
      }
    }
    return ans;
  }
 
 private:
  struct Node {
    Node *parent;
    double value;
    Node () {
      parent = this;
      value = 1;
    }
  };

  unordered_map<string, Node*> node_map_;

  Node *FindParent(Node *node) {
    if (node->parent != node) {
      node->parent = FindParent(node->parent);
    }
    return node->parent;
  }

  void UnionSets(Node *node0, Node *node1, double value) {
    Node *p0 = FindParent(node0);
    Node *p1 = FindParent(node1);

    double rate = node0->value / node1->value / value;
    for (auto node_pair : node_map_) {
      if (node_pair.second->parent == p1) {
        node_pair.second->parent = p0;
        node_pair.second->value = node_pair.second->value * rate;
      }
    }
  }
};
