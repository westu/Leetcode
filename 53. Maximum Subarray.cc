class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int>& nums) {
        if (nums.empty() == true) {
            return 0;
        }
        int len = static_cast<int>(nums.size());
        int ans = nums.at(0);
        int prev = nums.at(0);
        for (int i = 1; i < len; ++i) {
            int tmp = prev > 0 ? prev + nums.at(i) : nums.at(i);
            ans = max(ans, tmp);
            prev = tmp;
        }
        return ans;
    }
};
