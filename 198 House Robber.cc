class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.at(0);
        }
        vector<int> house_money(nums.size() + 1);
        house_money.at(0) = 0;
        house_money.at(1) = nums.at(0);
        for (int i = 1; i < nums.size(); ++i) {
            house_money.at(i + 1) = max(house_money.at(i), house_money.at(i - 1) + nums.at(i));
        }
        return house_money.at(nums.size());
    }
};
