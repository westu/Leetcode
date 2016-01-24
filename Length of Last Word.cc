class Solution {
 public:
  /**
   * @param s A string
   * @return the length of last word
   */
  int lengthOfLastWord(string s) {
    int ans(0);
    for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
      if (ans == 0 && *it == ' ') {
        continue;
      }
      if (*it == ' ') {
        break;
      }
      ++ans;
    }
    return ans;
  }
};
