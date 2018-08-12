class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty() == true) {
            return (vector<int>(2, -1));
        }
        int s = 0;
        int t = static_cast<int>(nums.size());
        while (s < t) {
            int mid = s + (t - s) / 2;
            if (nums[mid] >= target) {
                t = mid;
            } else {
                s = mid + 1;
            }
        }
        vector<int> ans(2);
        ans[0] = nums[s] == target ? s : -1;
        s = 0;
        t = static_cast<int>(nums.size());
        while (s < t) {
            int mid = s + (t - s) / 2;
            if (nums[mid] <= target) {
                s = mid + 1;
            } else {
                t = mid;
            }
        }
        ans[1] = nums[t - 1] == target ? t - 1 : -1;
        return ans;
    }
};
