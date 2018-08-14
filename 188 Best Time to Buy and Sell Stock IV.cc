class Solution {
 public:
  /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
  int maxProfit(int K, vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }

    int len(static_cast<int>(prices.size()));
    if (K >= len / 2) {
      int res(0);
      for (int i = 1; i < len; ++i) {
        res += max(0, prices.at(i) - prices.at(i - 1));
      }
      return res;
    }
      
    vector<int> buy(K + 1, INT_MIN), sell(K + 1, 0);
    for (int price : prices) {
      for (int i = 1; i <= K; ++i) {
        buy[i] = max(buy[i], sell[i - 1] - price);
        sell[i] = max(sell[i], buy[i] + price);
      }
    }
    return sell[K];

    // Solution 2:
    // vector<vector<int>> sell(len + 1, vector<int>(K + 1, 0));
    // vector<vector<int>> global(len + 1, vector<int>(K + 1, 0));
    // for (int i = 2; i <= len; ++i) {
    //   for (int j = 1; j <= K; ++j) {
    //     sell[i][j] = max(sell[i - 1][j] + prices[i -1] - prices[i - 2],
    //           global[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
    //    global[i][j] = max(global[i - 1][j], sell[i][j]);
    //   }
    // }
    // return global[len][K];
  }
};
