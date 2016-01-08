class Solution {
 public:
  int largestRectangleArea(vector<int>& height) {
    if (height.empty() == true) {
      return 0;
    }
    height.push_back(0);
    int max_s = 0;
    std::stack<int> st;
    for (int i = 0; i < static_cast<int>(height.size()); ++i) {
      if (st.empty() == true || height.at(i) >= height.at(st.top())) {
        st.push(i);
      } else {
        while (st.empty() == false && height.at(st.top()) > height.at(i)) {
          int w = st.top();
          st.pop();
          int last_w = st.empty() == true ? -1 : st.top();
          max_s = std::max(max_s, height.at(w) * (i - 1 - last_w));
        }
        st.push(i);
      }
    }
    return max_s;
  }
};
