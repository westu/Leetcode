class Solution {
 public:
  /**
   * @param arr: an array of integers
   * @return: number of chunks
   */
  int maxChunksToSorted(vector<int> &arr) {
    if (arr.empty()) {
      return 0;
    }
    int len(arr.size());
    vector<int> right_min(len, 0);
    right_min[len - 1] = arr[len - 1];
    for (int i = len - 2; i >= 0; --i) {
      right_min[i] = min(right_min[i + 1], arr[i]);
    }
    int left_max(0), res(0);
    for (int i = 0; i < len - 1; ++i) {
      left_max = max(left_max, arr[i]);
      if (left_max <= right_min[i + 1]) {
        ++res;  // ending of a part
      }
    }
    return res + 1;  // including the last one
  }
};
