// segment tree
class NumArray {
 public:
  NumArray(vector<int> nums) {
    len_ = static_cast<int>(nums.size());
    seg_tree_ = vector<int>(2 * len_, 0);
    for (int i = 0; i < len_; ++i) {
      update(i, nums.at(i));
    }
  }
  
  void update(int i, int val) {
    int pos = i + len_;
    seg_tree_.at(pos) = val;
    while (pos > 0) {
      int left(pos), right(pos);
      if (pos % 2 == 0) {
        ++right;  // left child is 2 * n
      } else {
        --left;
      }
      pos /= 2;  // parent point
      seg_tree_.at(pos) = seg_tree_.at(left) + seg_tree_.at(right);
    }
  }
  
  int sumRange(int i, int j) {
    int sum(0);
    i += len_;
    j += len_;
    while (i <= j) {
      if (i % 2 == 1) {  // i should be left child
        sum += seg_tree_.at(i);
        ++i;
      }
      if (j % 2 == 0) {
        sum += seg_tree_.at(j);
        --j;
      }
      i /= 2;
      j /= 2;
    }
    return sum;
  }

 private:
  vector<int> seg_tree_;
  int len_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
