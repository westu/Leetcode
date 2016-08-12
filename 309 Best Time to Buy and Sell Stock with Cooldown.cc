class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = static_cast<int>(prices.size());
        if (l < 2) {
            return 0;
        }
        
        int prev_min_profit = prices[0];
        int ans = 0;        
        vector<int> profit_record(l, 0);
        for (int i = 1; i < l; ++i) {
            int profit_i = prices.at(i) - prev_min_profit;
            ans = max(ans, profit_i);
            profit_record.at(i) = ans;
            prev_min_profit = min(prev_min_profit,
                i >= 2 ? prices.at(i) - profit_record.at(i - 2) : prices.at(i));
        }
        return ans;
    }
};
