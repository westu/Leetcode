class Solution {
 public:
  /**
   * @param nums: nums an array of scores
   * @return: check if player 1 will win
   */
  bool PredictTheWinner(vector<int> &nums) {
    int len(static_cast<int>(nums.size()));
    vector<int> sum(len + 1, 0);
    vector<vector<int>> max_score(len + 1, vector<int>(len + 1, 0));
    // max_score[l][r] means max score of first player in range [l..r]
    for (int i = 0; i < len; ++i) {
      sum.at(i + 1) = sum.at(i) + nums.at(i);
      max_score.at(i + 1).at(i + 1) = nums.at(i);
    }
    for (int i = 2; i <= len; ++i) {
      for (int l = 1; l <= len; ++l) {
        int r(l + i - 1);
        if (r <= len) {
          max_score.at(l).at(r) = max(
              nums.at(l - 1) + (get_sum(sum, l + 1, r) - max_score.at(l + 1).at(r)),
              (get_sum(sum, l, r - 1) - max_score.at(l).at(r - 1)) + nums.at(r - 1));
        }
      }
    }

    return max_score.at(1).at(len) >= get_sum(sum, 1, len) - max_score.at(1).at(len);
  }

 private:
  int get_sum(const vector<int> &sum, int l, int r) {
    return sum.at(r) - sum.at(l - 1);
  }
};

// class Solution {
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         int l = static_cast<int>(nums.size());
//         vector<vector<int>> sum(l + 1, vector<int>(l + 1, 0)),
//             score1(l + 1, vector<int>(l + 1, 0)), score2(l + 1, vector<int>(l + 1, 0));
//         for (int i = 1; i <= l; ++i) {
//             for (int j = i; j <= l; ++j) {
//                 sum.at(i).at(j) = sum.at(i).at(j - 1) + nums.at(j - 1);
//             }
//         }
        
//         for (int i = 1; i <= l; ++i) {  // length is 1
//             score1[i][i] = nums.at(i - 1);
//             score2[i][i] = nums.at(i - 1);
//         }
        
//         for (int i = 2; i <= l; ++i) {  // i is the length
//             for (int j = 1; j <= l - i + 1; ++j) {
//                 score1[j][j + i - 1] = max(nums[j - 1] + sum[j + 1][j + i - 1] - score2[j + 1][j + i - 1],
//                     nums[j + i - 2] + sum[j][j + i - 2] - score2[j][j + i - 2]);
//                 score2[j][j + i - 1] = max(nums[j - 1] + sum[j + 1][j + i - 1] - score1[j + 1][j + i - 1],
//                     nums[j + i - 2] + sum[j][j + i - 2] - score1[j][j + i - 2]);
//             }
//         }
        
//         return score1[1][l] >= (sum[1][l] - score1[1][l]);
//     }
// };
