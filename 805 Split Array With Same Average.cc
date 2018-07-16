class Solution {
 public:
  bool splitArraySameAverage(vector<int>& A) {
    int len(A.size()), half_len(A.size() / 2);
    vector<unordered_set<int>> sum_set(len + 1);
    sum_set[0].insert(0);
    int total_sum(0);
    for (int num : A) {
      for (int i = half_len; i >= 1; --i) {
        for (int sum : sum_set[i - 1]) {
          sum_set[i].insert(sum + num);
        }
      }
      total_sum += num;
    }
    for (int i = 1; i <= half_len; ++i) {
      if (total_sum * i % len == 0 &&
          sum_set[i].find(total_sum * i / len) != sum_set[i].end()) {
        return true;
      }
    }
    return false;
  }
};
