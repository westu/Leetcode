class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    if (len == 1) {
      return 0;
    }
    int l(0), r(len);
    while (l < r - 1) {
      int mid = l + (r - l) / 2;
      if (nums.at(mid - 1) < nums.at(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return r - 1;
  }
};
