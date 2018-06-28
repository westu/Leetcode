class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid.at(0).empty()) {
      return 0;
    }
    int num(0), h(static_cast<int>(grid.size())), w(static_cast<int>(grid.at(0).size()));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (grid.at(i).at(j) == '1') {
          ++num;
          queue<pair<int, int>> island_list;
          island_list.push(make_pair(i, j));
          grid.at(i).at(j) = '0';

          while (!island_list.empty()) {
            pair<int, int> point = island_list.front();
            island_list.pop();
            for (int k = -1; k <= 1; ++k) {
              for (int l = -1; l <= 1; ++l) {
                if (abs(k) + abs(l) == 1 && is_island(grid, point.first + k, point.second + l)) {
                  island_list.push(make_pair(point.first + k, point.second + l));
                  grid.at(point.first + k).at(point.second + l) = '0';
                }
              }
            }
          }
        }
      }
    }
    return num;
  }

 private:
  bool is_island(const vector<vector<char>> &grid, int x, int y) {
    return x >= 0 && x < static_cast<int>(grid.size()) &&
           y >= 0 && y < static_cast<int>(grid.at(0).size()) &&
           grid.at(x).at(y) == '1';
  }
};
