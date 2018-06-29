class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> matrix) {
    row_ = static_cast<int>(matrix.size());
    col_ = static_cast<int>(matrix.at(0).size());
    index_tree_ = vector<vector<int>>(row_ + 1, vector<int>(col_ + 1, 0));
    nums_ = vector<vector<int>>(row_ + 1, vector<int>(col_ + 1, 0));
    for (int i = 1; i <= row_; ++i) {
      for (int j = 1; j <= col_; ++j) {
        insert(i, j, matrix.at(i - 1).at(j - 1));
      }
    }
  }
  
  void update(int row, int col, int val) {
    insert(row + 1, col + 1, val);
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum(row2 + 1, col2 + 1) - sum(row2 + 1, col1) -
           sum(row1, col2 + 1) + sum(row1, col1);
  }

 private:
  vector<vector<int>> index_tree_;
  vector<vector<int>> nums_;
  int row_;
  int col_;

  void insert(int row, int col, int val) {
    for (int i = row; i <= row_; i += i & (-i)) {
      for (int j = col; j <= col_; j += j & (-j)) {
        index_tree_.at(i).at(j) += val - nums_.at(row).at(col);
      }
    }
    nums_.at(row).at(col) = val;
  }

  int sum(int row, int col) {
    int sum(0);
    for (int i = row; i > 0; i -= i & (-i)) {
      for (int j = col; j > 0; j -= j & (-j)) {
        sum += index_tree_.at(i).at(j);
      }
    }
    return sum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
 
