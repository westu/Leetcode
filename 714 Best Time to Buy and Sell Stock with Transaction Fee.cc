class Solution {
 public:
  /**
   * @param prices: a list of integers
   * @param fee: a integer
   * @return: return a integer
   */
  int maxProfit(vector<int> &prices, int fee) {
    if (prices.empty()) {
      return 0;
    }
    int len(static_cast<int>(prices.size()));
    vector<int> sell(len + 1, 0), buy(len + 1, 0);
    buy[1] = -prices[0];
    for (int i = 2; i <= len; ++i) {
      buy[i] = max(buy[i - 1], sell[i - 1] - prices[i - 1]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i - 1] - fee);
    }
    return sell[len];
  }
};
