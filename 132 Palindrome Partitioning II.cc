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
      for (int j = 1; j <= i; ++j) {
        // if (IsPalindrome(s.substr(j - 1, i - j + 1))) {  // IsPalindrome(string)
        // it can be easier to understand, which is shown below
        if (IsPalindrome(s, j - 1, i - 1)) {  // check [j .. i]
          min_cut[i] = min(min_cut[i], min_cut[j - 1] + 1);
        }
      }
    }
    return min_cut[len];
  }

 private:
  bool IsPalindrome(const string &s, int s_pos, int e_pos) {
    while (s_pos < e_pos) {
      if (s[s_pos] != s[e_pos]) {
        return false;
      }
      ++s_pos;
      --e_pos;
    }
    return true;
  }
};
