class UnionFind {
 public:
  UnionFind(int num) {
    root_ = vector<int>(num, 0);
    size_ = vector<int>(num, 1);
    for (int i = 0; i < num; ++i) {
      root_[i] = i;
    }
  }

  int GetRoot(int idx) {
    if (root_[idx] != idx) {
      root_[idx] = GetRoot(root_[idx]);
    }
    return root_[idx];
  }

  void Union(int idx0, int idx1) {
    int root0 = GetRoot(idx0);
    int root1 = GetRoot(idx1);
    if (root0 != root1) {
      root_[root0] = root_[root1];
      size_[root1] += size_[root0];
    }
  }

  int GetSize(int idx) {
    return size_[GetRoot(idx)];
  }

 private:
  vector<int> root_, size_;
};

class Solution {
 public:
  /**
   * @param grid: a grid
   * @param hits: some erasures order
   * @return: an array representing the number of bricks that will drop after each erasure in sequence
   */
  vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int rows(grid.size()), cols(grid[0].size());
    UnionFind union_find(rows * cols + 1);
    for (auto &hit : hits) {
      if (grid[hit[0]][hit[1]] == 0) {  // invalid hit
        hit[0] = -1;
        hit[1] = -1;
      } else {
        grid[hit[0]][hit[1]] = 0;
      }
    }

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1) {
          if (i == 0) {
            union_find.Union(0, i * cols + j + 1);
          }
          for (auto &dir : dirs) {
            int x(i + dir.first), y(j + dir.second);
            if (0 <= x && x < rows && 0 <= y && y < cols && grid[x][y] == 1) {
              union_find.Union(i * cols + j + 1, x * cols + y + 1);
              // this method will check if their roots are same
            }
          }
        }
      }
    }

    vector<int> res;
    int last_size = union_find.GetSize(0);
    for (int i = hits.size() - 1; i >= 0; --i) {
      if (hits[i][0] == -1) {
        res.push_back(0);
        continue;
      }
      grid[hits[i][0]][hits[i][1]] = 1;
      if (hits[i][0] == 0) {
        union_find.Union(0, hits[i][0] * cols + hits[i][1] + 1);
        // build relationship between top layer's node and the super No.0 node
      }
      for (auto &dir : dirs) {
        int x(hits[i][0] + dir.first), y(hits[i][1] + dir.second);
        if (0 <= x && x < rows && 0 <= y && y < cols && grid[x][y] == 1) {
          union_find.Union(hits[i][0] * cols + hits[i][1] + 1, x * cols + y + 1);
        }
      }
      int this_size(union_find.GetSize(0));
      if (this_size > last_size + 1) {
        res.push_back(this_size - last_size - 1);
      } else {
        res.push_back(0);
      }
      last_size = this_size;
    }
    reverse(res.begin(), res.end());
    return res;
  }

 private:
  pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
