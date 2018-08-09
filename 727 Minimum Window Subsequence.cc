class Solution {
 public:
  /**
   * @param S: a string
   * @param T: a string
   * @return: the minimum substring of S
   */
  string minWindow(string &S, string &T) {
    if (S.size() < T.size()) {
      return "";
    }
    int slen(S.size()), tlen(T.size());
    int start_pos(-1), min_len(-1);
    vector<vector<int>> start_p(slen + 1, vector<int>(tlen + 1, -1));  // -1 means not solved
    for (int i = 0; i <= slen; ++i) {
      start_p[i][0] = i;
    }
    for (int i = 1; i <= slen; ++i) {
      for (int j = 1; j <= min(i, tlen); ++j) {
        start_p[i][j] = S[i - 1] == T[j - 1] ? start_p[i - 1][j - 1] : start_p[i - 1][j];
      }
      if (start_p[i][tlen] != -1 && (min_len == -1 || i - start_p[i][tlen] < min_len)) {
        start_pos = start_p[i][tlen];
        min_len = i - start_p[i][tlen];
      }
    }
    return start_pos == -1 ? "" : S.substr(start_pos, min_len);
  }
};
