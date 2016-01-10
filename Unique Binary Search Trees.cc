class Solution {
 public:
  int numTrees(int n) {
    vector<int> f;
    f.push_back(1);  // f[0] = 1
    f.push_back(1);  // f[1] = 1
    for (int i = 2; i <= n; ++i) {
      int v = 0;
      for (int j = 1; j <= i; ++j) {
        v += f[j - 1] * f[i - j];
      }
      f.push_back(v);
    }
    return f.at(n);
  }
};
