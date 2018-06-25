// Union-find
class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, int> parent;
    for (vector<int> &edge : edges) {
      if (parent.find(edge.at(0)) == parent.end()) {
        parent[edge.at(0)] = edge.at(0);
      }
      if (parent.find(edge.at(1)) == parent.end()) {
        parent[edge.at(1)] = edge.at(1);
      }
      if (!union_set(edge.at(0), edge.at(1), parent)) {
        return edge;
      }
    }
  }

 private:
  int find_parent(unordered_map<int, int> &parent, int v) {
    if (parent.find(v)->second != v) {
      parent.find(v)->second = find_parent(parent, parent.find(v)->second);
    }
    return parent.find(v)->second;
  }
  bool union_set(int v0, int v1, unordered_map<int, int> &parent) {
    int p0 = find_parent(parent, v0);
    int p1 = find_parent(parent, v1);
    if (p0 == p1) {
      return false;
    }
    parent.find(p0)->second = p1;
    return true;
  }
};

// DFS
// class Solution {
// public:
//   vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//     unordered_map<int, vector<int>> graph;
//     for (const vector<int> &v_pair : edges) {
//       int v0 = v_pair.at(0);
//       int v1 = v_pair.at(1);
//       if (graph.find(v0) == graph.end()) {
//         vector<int> neighbor;
//         graph[v0] = neighbor;
//       }
//       graph[v0].push_back(v1);
//       if (graph.find(v1) == graph.end()) {
//         vector<int> neighbor;
//         graph[v1] = neighbor;
//       }
//       graph[v1].push_back(v0);
//
//       unordered_set<int> visited;
//       if (find_cricle(graph, v0, visited)) {
//         return v_pair;
//       }
//     }
//   }
//
//  private:
//   bool find_cricle(const unordered_map<int, vector<int>> &graph, int v, unordered_set<int> &visited) {
//     visited.insert(v);
//     for (int neighbor : graph.find(v)->second) {
//       if (dfs(graph, neighbor, v, visited)) {
//         return true;
//       }
//     }
//     return false;
//   }
//
//   bool dfs(const unordered_map<int, vector<int>> &graph,
//       int v, int from, unordered_set<int> &visited) {
//     if (visited.find(v) != visited.end()) {
//       return true;
//     }
//     visited.insert(v);
//     for (int neighbor : graph.find(v)->second) {
//       if (neighbor != from && dfs(graph, neighbor, v, visited)) {
//         return true;
//       }
//     }
//     return false;
//   }
// };
