
class Solution {
 public:
  /**
   * @param n: a integer
   * @param flights: a 2D array
   * @param src: a integer
   * @param dst: a integer
   * @param K: a integer
   * @return: return a integer
   */
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    vector<vector<int>> dp(K + 2, vector<int>(n, -1));  // -1 means not valued
    dp[0][src] = 0;
    for (int i = 1; i <= K + 1; ++i) {
      dp[i][src] = 0;
      for (auto flight : flights) {
        if (dp[i - 1][flight[0]] != -1) {
          if (dp[i][flight[1]] == -1) {
            dp[i][flight[1]] = dp[i - 1][flight[0]] + flight[2];
          } else {
            dp[i][flight[1]] = min(dp[i][flight[1]], dp[i - 1][flight[0]] + flight[2]);
          }
        }
      }
    }
    return dp[K + 1][dst];
  }
};
