class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = static_cast<int>(nums.size());
        int i = 0;
        for (int j = 0; j < l; ++j) {
            if (nums.at(j) != 0) {
                nums.at(i++) = nums.at(j);
            }
        }
        for (int j = i; j < l; ++j) {
            nums.at(j) = 0;
        }
    }
};
