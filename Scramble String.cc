class Solution {
 public:
  /**
   * @param s1 A string
   * @param s2 Another string
   * @return whether s2 is a scrambled string of s1
   */
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) {
      return false;
    }
    int len = static_cast<int>(s1.size());
    vector<vector<vector<bool> > > dp(len,
      vector<vector<bool> >(len, vector<bool>(len + 1, false)));
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        dp[i][j][0] = true;
        dp[i][j][1] = s1.at(i) == s2.at(j);
      }
    }
    for (int l = 1; l <= len; ++l) {
      for (int i = 0; (i + l - 1) < len; ++i) {
        for (int j = 0; (j + l - 1) < len; ++j) {
          for (int k = 1; k <= l - 1; ++k) {
            if (dp[i][j][k] == true && dp[i + k][j + k][l -k] == true ||
                dp[i][j + l - k][k] == true && dp[i + k][j][l - k] == true) {
              dp[i][j][l] = true;
              break;
            }
          }
        }
      }
    }
    return dp[0][0][len];
  }
};
