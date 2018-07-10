class Solution {
public:
  /**
   * @param A: an array
   * @return: total of reverse pairs
   */
  long long reversePairs(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int len(static_cast<int>(nums.size()));
    return MergeSort(nums, 0, len);
  }

 private:
  long long MergeSort(vector<int> &nums, int l, int r) {
    if (l + 1 == r) {
      return 0;
    }
    long long res = 0;
    int mid = l + (r - l) / 2;
    res = MergeSort(nums, l, mid) + MergeSort(nums, mid, r);
    int i(l), j(mid);
    
    while (i < mid && j < r) {
      int delta_j(0);
      while (j + delta_j < r && nums.at(j + delta_j) < nums.at(i) / 2.0) {
        ++delta_j;
      }
      res += (mid - i) * delta_j;
      j += delta_j;
      ++i;
    }
    
    // Solution 2
    // while (i < mid && j < r) {
    //   if (nums.at(i) / 2.0 <= nums.at(j)) {
    //     ++i;
    //     if (i < mid) {
    //       res += j - mid;
    //     }
    //   } else {
    //     ++j;
    //     ++res;
    //   }
    // }
    // if (mid - 1 > i) {
    //   res += (mid - i - 1) * (r - mid);
    // }
    
    sort(nums.begin() + l, nums.begin() + r);
    return res;
  }
};
