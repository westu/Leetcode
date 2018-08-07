class Solution {
 public:
   /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
  int rob(vector<int> &nums) {
    int len(nums.size());
    if (len == 0) {
     return 0;
    }
    if (len == 1) {
      return nums[0];
    }

    return max(MaxMoney(nums, 0, len - 1), MaxMoney(nums, 1, len));
  }

 private:
  int MaxMoney(const vector<int> &nums, int start, int end) {
    if (end - start == 1) {
      return nums[start];
    }
    vector<int> max_m(end - start, 0);
    max_m[0] = nums[start + 0];
    max_m[1] = max(nums[start + 1], max_m[0]);
    for (int i = start + 2; i < end; ++i) {
      max_m[i - start] = max(max_m[i - start - 1],  max_m[i - start - 2] + nums[i]);
    }
    return max_m[end - 1 - start];
  }
};
