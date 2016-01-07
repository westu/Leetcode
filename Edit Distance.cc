class Solution {
 public:
  int minDistance(string word1, string word2) {
    int l1 = static_cast<int>(word1.size());
    int l2 = static_cast<int>(word2.size());
    vector<vector<int> > dis(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l2; ++i) {
      dis[0][i] = i;
    }
    for (int i = 1; i <= l1; ++i) {
      dis[i][0] = i;
    }
    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        if (word1.at(i - 1) == word2.at(j - 1)) {
          dis[i][j] = min(dis[i - 1][j] + 1, min(dis[i][j - 1] + 1, dis[i - 1][j - 1]));
        } else {
          dis[i][j] = min(dis[i - 1][j] + 1, min(dis[i][j - 1] + 1, dis[i - 1][j - 1] + 1));
        }
      }
    }
    return dis[l1][l2];
  }
};
