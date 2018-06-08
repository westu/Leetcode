class Solution {
    struct Point {
      vector<string> parents;
      vector<double> pvalues;
      vector<string> children;
      vector<double> cvalues;
    };

public:
    vector<double> calcEquation(
        vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
      vector<double> result;
      if (equations.empty()) {
        return result;
      }
      unordered_map<string, Point> points;
      for (int i = 0; i < static_cast<int>(equations.size()); ++i) {
        const string& parent = equations.at(i).first;
        const string& child = equations.at(i).second;
        if (points.find(parent) == points.end()) {
          points.insert(make_pair(parent, Point()));
        }
        points.find(parent)->second.children.push_back(child);
        points.find(parent)->second.cvalues.push_back(values.at(i));
        if (points.find(child) == points.end()) {
          points.insert(make_pair(child, Point()));
        }
        points.find(child)->second.parents.push_back(parent);
        points.find(child)->second.pvalues.push_back(1.0 / values.at(i));
      }

      for (int i = 0; i < static_cast<int>(queries.size()); ++i) {
        const string& parent = queries.at(i).first;
        const string& child = queries.at(i).second;

        unordered_set<string> has_visited;
        if (!dfs(points, parent, child, 1.0, result, has_visited)) {
            result.push_back(-1.0);
        }
      }

      return result;
    }

private:
    bool dfs(const unordered_map<string, Point>& points,
             const string& pname,
             const string& des,
             double ans,
             vector<double>& result,
             unordered_set<string> has_visited) {
      if (points.find(pname) == points.end() || has_visited.find(pname) != has_visited.end()) {
          return false;
      }
      has_visited.insert(pname);
    
      Point point = points.find(pname)->second;
      for (int i = 0; i < static_cast<int>(point.parents.size()); ++i) {
        if (point.parents.at(i) == des) {
          result.push_back(ans * point.pvalues.at(i));
          return true;
        } else {
          if (dfs(points, point.parents.at(i), des, ans * point.pvalues.at(i), result, has_visited)) {
            return true;
          }
        }
      }
      for (int i = 0; i < static_cast<int>(point.children.size()); ++i) {
        if (point.children.at(i) == des) {
          result.push_back(ans * point.cvalues.at(i));
          return true;
        } else {
          if (dfs(points, point.children.at(i), des, ans * point.cvalues.at(i), result, has_visited)) {
            return true;
          }
        }
      }
      return false;
    }
};
