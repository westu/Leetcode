class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int reach_pos = 0;
    int len = static_cast<int>(nums.size());
    for (int i = 0; i < len && i <= reach_pos; ++i) {
      reach_pos = std::max(reach_pos, i + nums[i]);
      if (reach_pos >= len - 1) {
        break;
      }
    }
    return reach_pos >= len - 1;
  }
};
