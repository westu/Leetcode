class Solution {
 public:
  int numDistinct(string s, string t) {
    int l1 = static_cast<int>(s.size());
    int l2 = static_cast<int>(t.size());
    vector<vector<int> > dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        if (s.at(i - 1) == t.at(j - 1)) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[l1][l2];
  }
};
