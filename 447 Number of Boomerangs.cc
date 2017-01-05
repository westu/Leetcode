class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
      int ans(0);

      for (int i = 0; i < points.size(); ++i) {
        unordered_map<int, int> dis_table;
        for (int j = 0; j < points.size(); ++j) {
          if (i != j) {
            int dis_ij = cal_dis(points.at(i), points.at(j));
            // auto it = dis_table.find(dis_ij);
            // if (it == dis_table.end()) {
            //   dis_table.insert(make_pair(dis_ij, 1));
            // } else {
            //   it->second = it->second + 1;
            // }
            ++dis_table[dis_ij];
          }
        }

        for (auto it : dis_table) {
          ans += it.second * (it.second - 1);
        }
      }
      return ans;
    }

private:
    int cal_dis(const pair<int, int> &p1, const pair<int, int> &p2) {
        return (p1.first - p2.first) * (p1.first - p2.first) +
            (p1.second - p2.second) * (p1.second - p2.second);
    }
};
