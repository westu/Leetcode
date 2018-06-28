class NumArray {
 public:
  NumArray(vector<int> nums) {
    len_ = static_cast<int>(nums.size());
    index_tree_ = vector<int>(len_ + 1, 0);
    nums_ = vector<int>(len_ + 1, 0);
    for (int i = 0; i < len_; ++i) {
      insert(i + 1, nums.at(i));
    }
  }
  
  void update(int i, int val) {
    insert(i + 1, val);  // index tree using index from 1
  }
  
  int sumRange(int i, int j) {
    return sum(j + 1) - sum(i);
  }

 private:
  vector<int> index_tree_;
  vector<int> nums_;
  int len_;

  void insert(int pos, int val) {
    for (int i = pos; i <= len_; i += i & (-i)) {
      index_tree_.at(i) += val - nums_.at(pos);
    }
    nums_.at(pos) = val;
  }

  int sum(int pos) {
    int sum(0);
    for (int i = pos; i > 0; i -= i & (-i)) {
      sum += index_tree_.at(i);
    }
    return sum;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

// class NumArray {
// public:
//     NumArray(vector<int> &nums) {
//         int l = static_cast<int>(nums.size()) + 1;
//         binary_indexed_tree = vector<int>(l, 0);
//         prev_num = vector<int>(l, 0);
//         for (int i = 1; i < l; ++i) {
//             update(i - 1, nums.at(i - 1));
//         }
//     }

//     void update(int i, int val) {
//         int j = i + 1;
//         while (j < binary_indexed_tree.size()) {
//             binary_indexed_tree.at(j) += val - prev_num.at(i + 1);
//             j += j & (-j);
//         }
//         prev_num.at(i + 1) = val;
//     }

//     int sumRange(int i, int j) {
//         return get_sum(j + 1) - get_sum(i);
//     }

// private:
//     vector<int> binary_indexed_tree;
//     vector<int> prev_num;
    
//     int get_sum(int i) {
//         int sum = 0;
//         while (i > 0) {
//             sum += binary_indexed_tree.at(i);
//             i -= i & (-i);
//         }
//         return sum;
//     }
// };
