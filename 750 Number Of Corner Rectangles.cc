class Solution {
 public:
  /**
   * @param grid: the grid
   * @return: the number of corner rectangles
   */
  int countCornerRectangles(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int rows(grid.size()), cols(grid[0].size()), ans(0);
    for (int i = 0; i < rows; ++i) {
      vector<int> one_pos;
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j]) {
          one_pos.push_back(j);
        }
      }
      for (int j = i + 1; j < rows; ++j) {
        int num(0);
        for (int pos : one_pos) {
          if (grid[j][pos]) {
            ++num;
          }
        }
        ans += num * (num - 1) / 2;
      }
    }
    return ans;
  }
};
