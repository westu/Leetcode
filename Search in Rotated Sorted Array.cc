class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int t = static_cast<int>(nums.size());
        while (s < t) {
            int mid = s + (t - s) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[s]) {
                if (nums[mid] > target && nums[s] <= target) {
                    t = mid;
                } else {
                    s = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[t - 1] >= target) {
                    s = mid + 1;
                } else {
                    t = mid;
                }
            }
        }
        return -1;
    }
};
