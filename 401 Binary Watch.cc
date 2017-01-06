class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    for (int i = 0; i < 1024; ++i) {
      if (count_one(i) == num) {
        int n(0), m(0), k(i);
        for (int j = 0; j < 4; ++j) {
          if (k & 1 == 1) {
            n += 1 << j;
          }
          k >>= 1;
        }

        for (int j = 0; j < 6; ++j) {
          if (k & 1 == 1) {
            m += 1 << j;
          }
          k >>= 1;
        }
        
        if (n < 12 && m < 60) {
          string this_ans = to_string(n) + ":";
          if (m < 10) {
            this_ans.push_back('0');
          }
          this_ans += to_string(m);
          ans.push_back(this_ans);
        }
      }
    }
    return ans;
  }

private:
  int count_one(int n) {
    int sum = 0;
    while (n > 0) {
      ++sum;
      n = n & (n - 1);
    }
    return sum;
  }
};
