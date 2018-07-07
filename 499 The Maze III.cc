class Solution {
 public:
  /**
   * @param maze: the maze
   * @param ball: the ball position
   * @param hole: the hole position
   * @return: the lexicographically smallest way
   */
  string findShortestWay(vector<vector<int>> &maze,
      vector<int> &start,
      vector<int> &destination) {
    queue<BfsStatus> bfs_queue;
    bfs_queue.push(BfsStatus(start.at(0), start.at(1), 0));
    
    set<string> ans_set;
    unordered_set<int> visited;
    int min_step(-1);
    
    while (!bfs_queue.empty()) {
      BfsStatus point = bfs_queue.front();
      bfs_queue.pop();
      visited.insert(HashValue(point.x_, point.y_, maze.size(), maze.at(0).size()));

      for (int i = 0; i < 4; ++i) {
        int x(point.x_), y(point.y_), moves(0);
        bool in_hole(false);
        while (is_not_wall(maze, x + dirs.at(i).at(0), y + dirs.at(i).at(1))) {
          ++moves;
          x += dirs.at(i).at(0);
          y += dirs.at(i).at(1);
          if (x == destination.at(0) && y == destination.at(1)) {
            if (min_step == -1 || point.steps_ + moves <= min_step) {
              if (point.steps_ + moves < min_step) {
                ans_set.clear();
              }
              ans_set.insert(point.dir_ + dirs2.at(i));
              min_step = point.steps_ + moves;
            }
            in_hole = true;
            break;
          }
        }
        if (!in_hole && visited.find(HashValue(x, y, maze.size(), maze.at(0).size())) == visited.end()) {
          bfs_queue.push(BfsStatus(x, y, point.steps_ + moves, point.dir_ + dirs2.at(i)));
        }
      }
    }

    if (ans_set.empty()) {
      return "impossible";
    } else {
      return *ans_set.begin();
    }
  }

 private:
  struct BfsStatus {
    int x_;
    int y_;
    int steps_;
    string dir_;

    BfsStatus(int x, int y, int steps, const string &dir = "") {
      x_ = x;
      y_ = y;
      steps_ = steps;
      dir_ = dir;
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

  vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
  vector<string> dirs2 = {"d", "l", "r", "u"};
};
