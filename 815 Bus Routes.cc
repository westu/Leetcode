class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (routes.empty()) {
      return -1;
    }
    unordered_map<int, vector<int>> point2set;
    queue<pair<int, int>> visit_queue;

    for (int i = 0; i < static_cast<int>(routes.size()); ++i) {
      for (int p : routes.at(i)) {
        if (point2set.find(p) == point2set.end()) {
          point2set.insert(make_pair(p, vector<int>()));
        }
        point2set[p].push_back(i);
      }
    }

    unordered_set<int> has_visited_point;
    unordered_set<int> has_visited_set;
    visit_queue.push(make_pair(S, 0));
    // the points which are in same route will get one more step
    has_visited_point.insert(S);
    while (!visit_queue.empty()) {
      pair<int, int> p = visit_queue.front();
      if (p.first == T) {
        return p.second;
      }
      visit_queue.pop();

      for (int next_set : point2set[p.first]) {
        if (has_visited_set.find(next_set) == has_visited_set.end()) {
          for (int next_p : routes.at(next_set)) {
            if (has_visited_point.find(next_p) == has_visited_point.end()) {
              visit_queue.push(make_pair(next_p, p.second + 1));
              has_visited_point.insert(next_p);
            }
          }
          has_visited_set.insert(next_set);
        }
      }
    }
    return -1;
  }
};
