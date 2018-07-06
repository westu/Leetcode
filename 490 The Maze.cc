class Solution {
 public:
  /**
   * @param maze: the maze
   * @param start: the start
   * @param destination: the destination
   * @return: whether the ball could stop at the destination
   */
  bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    unordered_set<int> visited;
    pair<int, int> start_pos = make_pair(start.at(0), start.at(1));
    pair<int, int> end_pos = make_pair(destination.at(0), destination.at(1));
    return Dfs(maze, start_pos, end_pos, visited);
  }

 private:
  bool Dfs(const vector<vector<int>> &maze,
      const pair<int, int> &start,
      const pair<int, int> &end,
      unordered_set<int> &visited) {
    if (start == end) {
      return true;
    }

    int rows(static_cast<int>(maze.size())), cols(static_cast<int>(maze.at(0).size()));
    visited.insert(HashValue(start.first, start.second, rows, cols));
    for (int i = 0; i < 4; ++i) {
      int x(start.first), y(start.second);
      while (is_not_wall(maze, x + dirs.at(i).at(0), y + dirs.at(i).at(1))) {
        x += dirs.at(i).at(0);
        y += dirs.at(i).at(1);
      }
      pair<int, int> pos = make_pair(x, y);
      if (visited.find(HashValue(x, y, rows, cols)) == visited.end() &&
          Dfs(maze, make_pair(x, y), end, visited)) {
        return true;
      }
    }
    return false;
  }

  int HashValue(int x, int y, int rows, int cols) {
    return x * cols + y;
  }

  bool is_not_wall(const vector<vector<int>> &maze, int x, int y) {
    return 0 <= x && x < static_cast<int>(maze.size()) &&
        0 <= y && y < static_cast<int>(maze.at(0).size()) &&
        maze.at(x).at(y) == 0;
  }

  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
