class Solution {
 public:
  /**
   * @param maze: the maze
   * @param start: the start
   * @param destination: the destination
   * @return: the shortest distance for the ball to stop at the destination
   */
  int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    // unordered_map<int, int> steps;
    // pair<int, int> start_pos = make_pair(start.at(0), start.at(1));
    // pair<int, int> end_pos = make_pair(destination.at(0), destination.at(1));
    // return Dfs(maze, start_pos, end_pos, steps);
    queue<BfsStatus> bfs_queue;
    bfs_queue.push(BfsStatus(start.at(0), start.at(1), 0));
    unordered_set<int> visited;
    while (!bfs_queue.empty()) {
      BfsStatus point = bfs_queue.front();
      bfs_queue.pop();
      visited.insert(HashValue(point.x_, point.y_, maze.size(), maze.at(0).size()));
      if (point.x_ == destination.at(0) && point.y_ == destination.at(1)) {
        return point.steps_;
      }

      for (int i = 0; i < 4; ++i) {
        int x(point.x_), y(point.y_), moves(0);
        while (is_not_wall(maze, x + dirs.at(i).at(0), y + dirs.at(i).at(1))) {
          ++moves;
          x += dirs.at(i).at(0);
          y += dirs.at(i).at(1);
        }
        if (visited.find(HashValue(x, y, maze.size(), maze.at(0).size())) == visited.end()) {
          bfs_queue.push(BfsStatus(x, y, point.steps_ + moves));
        }
      }
    }

    return -1;
  }

 private:
  struct BfsStatus {
    int x_;
    int y_;
    int steps_;

    BfsStatus(int x, int y, int steps) {
      x_ = x;
      y_ = y;
      steps_ = steps;
    }
  };

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
