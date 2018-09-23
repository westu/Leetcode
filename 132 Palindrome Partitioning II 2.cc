class Solution {
 public:
  /**
   * @param s: A string
   * @return: An integer
   */
  int minCut(string &s) {
    if (s.empty()) {
      return 0;
    }
    int len(s.size());
    vector<int> min_cut(len + 1, 0);
    for (int i = 0; i <= len; ++i) {
      min_cut[i] = i - 1;  // "aa" needs 1 + (-1) times cut
    }
    for (int i = 2; i <= len; ++i) {
      for (int j = 0; (i + j) <= len && (i - j) >= 1; ++j) {
        // check s[i - j, i + j] (odd length) is palindrome or not
        if (s[i - j - 1] != s[i + j - 1]) {
          break;
        }
        min_cut[i + j] = min(min_cut[i + j], min_cut[i - j - 1] + 1);
      }
      if (s[i - 1] == s[i - 1 - 1]) {
        // check s[i - 1 - j, i + j] (even length) is palindrome
        for (int j = 0; (i + j) <= len && (i - 1 - j) >= 1; ++j) {
          if (s[i + j - 1] != s[i - 1 - j - 1]) {
            break;
          }
          min_cut[i + j] = min(min_cut[i + j], min_cut[i - 1 - j - 1] + 1);
        }
      }
    }
    return min_cut[len];
  }
};
