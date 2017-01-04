class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }
        int len = static_cast<int>(nums.size());
        for (int i = 0; i < len; ++i) {
            int s = 0;
            while (nums.at(i) != i + 1) {
                if (nums.at(nums.at(i) - 1) == nums.at(i)) {
                    break;
                } else {
                    int tmp = nums.at(i);
                    nums.at(i) = nums.at(nums.at(i) - 1);
                    nums.at(tmp - 1) = tmp;
                }
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums.at(i) != i + 1) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
