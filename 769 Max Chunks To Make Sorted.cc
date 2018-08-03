class Solution {
 public:
  int maxChunksToSorted(vector<int> &arr) {
    if (arr.empty()) {
      return 0;
    }
    int result(0), seg_end(0), i(0);
    while (i < arr.size()) {
      if (arr[i] == i) {
        ++result;
        ++i;
      } else {
        seg_end = i;  // this segment starts from index i
        while (i <= seg_end) {
          seg_end = max(seg_end, arr[i]);
          ++i;
        }
        ++result;
      }
    }
    return result;
  }
};
