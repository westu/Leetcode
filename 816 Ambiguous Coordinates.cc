class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
      vector<string> ans;
      if (S.empty()) {
        return ans;
      }
      int len = static_cast<int>(S.size());
      for (int i = 1; i < len - 2; ++i) {  // add comma after S.at(i)
        for (int j = 1; j <= i; ++j) {  // add decimal point after S.at(j)
          for (int k = i + 1; k <= len - 2; ++k) {  // add another decimal point after S.at(k)
            if (isvalid(S, 1, i, j) && isvalid(S, i + 1, len - 2, k)) {
              string str = "(";
              for (int l = 1; l < len - 1; ++l) {
                str.push_back(S.at(l));
                if (l == i) {
                  str += ", ";
                } else if (l == j && j < i) {
                  str.push_back('.');
                } else if (l == k && k < len - 2) {
                  str.push_back('.');
                }
              }
              str += ")";
              ans.push_back(str);
            }
          }
        }
      }
      return ans;
    }

private:
    bool isvalid(const string &S, int head, int tail, int point) {
      if (point > head && S.at(head) == '0') {  // startswith 0
        return false;
      }
      if (point < tail && S.at(tail) == '0') {  // endswith 0
        return false;
      }

      return true;
    }
};
