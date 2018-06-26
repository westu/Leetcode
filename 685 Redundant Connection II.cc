class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    bool has_2_indegree = false;
    int first_in_edge, second_in_edge;

    unordered_map<int, int> in_edge;
    for (int i = 0; i < static_cast<int>(edges.size()); ++i) {  // find vertex with in-degree as 2
      if (in_edge.find(edges.at(i).at(1)) == in_edge.end()) {
        in_edge[edges.at(i).at(1)] = i;
      } else {
        has_2_indegree = true;
        first_in_edge = in_edge[edges.at(i).at(1)];
        second_in_edge = i;
        break;
      }
    }

    unordered_map<int, int> parent;
    for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
      if (has_2_indegree && i == second_in_edge) {
        continue;
      }
      if (!union_set(edges.at(i).at(0), edges.at(i).at(1), parent)) {
        return has_2_indegree ? edges.at(first_in_edge) : edges.at(i);
      }
    }
    return edges.at(second_in_edge);
  }

 private:
  bool union_set(int v0, int v1, unordered_map<int, int> &parent) {
    int p0 = find_parent(v0, parent);
    int p1 = find_parent(v1, parent);
    if (p0 == p1) {
      return false;
    }
    parent[p0] = p1;
    return true;
  }

  int find_parent(int v, unordered_map<int, int> &parent) {
    if (parent.find(v) == parent.end()) {
      parent[v] = v;
    }
    if (v != parent[v]) {
      parent[v] = find_parent(parent[v], parent);
    }
    return parent[v];
  }
};
