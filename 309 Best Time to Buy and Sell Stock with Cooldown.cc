class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = static_cast<int>(prices.size());
        if (l < 2) {
            return 0;
        }
        
        priority_queue<int, vector<int>, greater<int> > profit;
        profit.push(prices[0]);
        int ans = 0;        
        vector<int> profit_record(l, 0);
        for (int i = 1; i < l; ++i) {
            int profit_i = prices.at(i) - profit.top();
            ans = max(ans, profit_i);
            profit_record.at(i) = ans;
            profit.push(i >= 2 ? prices.at(i) - profit_record.at(i - 2) : prices.at(i));
        }
        return ans;
    }
};
