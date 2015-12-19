class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        int ans, min_dis;
        min_dis = -1;  // initialization
        for (int i = 0; i <= (len - 3); i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                int l = i + 1;
                int r = len - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (min_dis == -1 || abs(sum - target) < min_dis) {
                        min_dis = abs(sum - target);
                        ans = sum;
                    }
                    if (sum <= target) {
                        l++;
                        while (l < len && nums[l] == nums[l - 1]) {
                            l++;
                        }
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
