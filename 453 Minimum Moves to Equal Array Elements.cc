class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int min_value = nums.at(0);
        for (int num : nums) {
            min_value = min(min_value, num);
        }
        int ans(0);
        for (int num : nums) {
            ans += num - min_value;
        }
        return ans;
    }
};
