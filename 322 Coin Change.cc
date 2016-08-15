class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) {
            return amount == 0;
        }
        sort(coins.begin(), coins.end());
        vector<int> min_num(amount + 1, -1);
        min_num.at(0) = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i - c >= 0 && min_num.at(i - c) >= 0) {
                    if (min_num.at(i) == -1) {
                        min_num.at(i) = min_num.at(i - c) + 1;
                    } else {
                        min_num.at(i) = min(min_num.at(i), min_num.at(i - c) + 1);
                    }
                }
            }
        }
        return min_num.at(amount);
    }
};
