class Solution {
 public:
  /**
   * @param s: A string
   * @param k: An integer
   * @return: An integer
   */
  int lengthOfLongestSubstringKDistinct(string &s, int k) {
    if (s.empty() || k == 0) {
      return 0;
    }
    int i(0), j(0);  // slide windows is [i, j)
    unordered_map<char, int> counter;
    int ans(0);
    while (j < static_cast<int>(s.size())) {
      if (static_cast<int>(counter.size()) <= k) {
        ++counter[s.at(j++)];
        if (static_cast<int>(counter.size()) <= k) {
          ans = max(ans, j - i);
        }
      } else {
        --counter[s.at(i)];
        if (counter[s.at(i)] == 0) {
          counter.erase(counter.find(s.at(i)));
        }
        ++i;
      }
    }
    return ans;
  }
};
