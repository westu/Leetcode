class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
        vector<int> sum_list(target + 1, 0);
        sum_list.at(0) = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto j = nums.begin(); j != nums.end(); ++j) {
                if (i - *j < 0) {
                    break;
                } else {
                    sum_list.at(i) += sum_list.at(i - *j);
                }
            }
        }
        return sum_list.at(target);
    }
};
