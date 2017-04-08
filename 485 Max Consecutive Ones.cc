class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans(0), count(0);
        for (int num : nums) {
            if (num == 1) {
                ++count;
            } else {
                ans = max(ans, count);
                count = 0;
            }
        }
        return max(ans, count);
    }
};
