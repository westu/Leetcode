class Solution {
 public:
  /**
   * @param nums: A list of integer
   * @return: An integer, maximum coins
   */
  int maxCoins(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int len(nums.size());
    vector<int> num_list(len + 2, 1);
    // add 1 at the beginning and end of nums
    for (int i = 0; i < len; ++i) {
      num_list[i + 1] = nums[i];
    }
    vector<vector<int>> max_coins(len + 2, vector<int>(len + 1, 0));
    for (int l = 1; l <= len; ++l) {
      for (int left = 1; left <= len; ++left) {
        int right = left + l - 1;
        if (right <= len) {
          for (int k = left; k <= right; ++k) {
            max_coins[left][right] = max(max_coins[left][right],
                num_list[left - 1] * num_list[k] * num_list[right + 1] +
                    max_coins[left][k - 1] + max_coins[k + 1][right]);
          }
        }
      }
    }
    return max_coins[1][len];
  }
};
