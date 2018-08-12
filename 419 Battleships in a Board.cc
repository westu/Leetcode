class Solution {
 public:
  /**
   * @param board: the given 2D board
   * @return: the number of battle ships
   */
  int countBattleships(vector<vector<char>> &board) {
    if (board.empty() || board.at(0).empty()) {
      return 0;
    }
    int res(0);
    for (int i = 0; i < static_cast<int>(board.size()); ++i) {
      for (int j = 0; j < static_cast<int>(board.at(0).size()); ++j) {
        if (board.at(i).at(j) == 'X' &&
            (i == 0 || board.at(i - 1).at(j) == '.') && (j == 0 || board.at(i).at(j - 1) == '.')) {
          ++res;
        }
      }
    }
    return res;
  }
};
