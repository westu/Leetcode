class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = static_cast<int>(nums.size());
        if (l < 3) {
            return false;
        }
        
        int min_v = nums.at(0);
        long long next_v = 1L << 32;
        for (int i = 1; i < l; ++i) {
            if (nums.at(i) < min_v) {
                min_v = nums.at(i);
            } else if (nums.at(i) > min_v && nums.at(i) < next_v) {
                next_v = nums.at(i);
            } else if (nums.at(i) > next_v) {
                return true;
            }
        }
        
        return false;
    }
};
