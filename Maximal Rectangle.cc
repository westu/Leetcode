class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() == true || matrix[0].empty() == true) {
      return 0;
    }
    int l1 = static_cast<int>(matrix.size());
    int l2 = static_cast<int>(matrix[0].size());
    std::vector<vector<int> > lens(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i < l1; ++i) {
      lens[i][0] = matrix[i][0] == '1' ? 1 : 0;
      for (int j = 1; j < l2; ++j) {
        lens[i][j] = matrix[i][j] == '1' ? lens[i][j - 1] + 1 : 0;
      }
    }
    int ans = 0;
    for (int i = 0; i < l2; ++i) {
      lens[l1][i] = -1;
      std::stack<int> st;
      for (int j = 0; j <= l1; ++j) {
        if (st.empty() == true|| lens[j][i] >= lens[st.top()][i]) {
          st.push(j);
        } else {
          while (st.empty() == false && lens[j][i] < lens[st.top()][i]) {
            int tmp = st.top();
            st.pop();
            int prev_ind = st.empty() == true ? -1 : st.top();
            ans = std::max(ans, lens[tmp][i] * (j - 1 - prev_ind));
          }
          st.push(j);
        }
      }
    }
    return ans;
  }
};
