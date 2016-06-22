class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix.at(0).empty()) {
          return 0;
        }
        int row = static_cast<int>(matrix.size());
        int col = static_cast<int>(matrix.at(0).size());
        vector<vector<int> > sq(row, vector<int>(col, 0));
        for (int i = 0; i < col; ++i) {
            sq.at(0).at(i) = matrix.at(0).at(i);
        }
        for (int i = 0; i < row; ++i) {
            sq.at(i).at(0) = matrix.at(i).at(0);
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix.at(i).at(j) == 0) {
                    sq.at(i).at(j) = 0;
                } else {
                    sq.at(i).at(j) = 1 + min(sq.at(i - 1).at(j - 1),
                        min(sq.at(i - 1).at(j), sq.at(i).at(j - 1)));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                ans = max(ans, sq.at(i).at(j) * sq.at(i).at(j));
            }
        }
        return ans;
    }
};

/**
 * Solution 2:
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.at(0).empty()) {
          return 0;
        }
        int row = static_cast<int>(matrix.size());
        int col = static_cast<int>(matrix.at(0).size());
        vector<vector<int> > one_sum(row + 1, vector<int>(col, 0));
        for (int i = 1; i <= row; ++i) {
          for (int j = 0; j < col; ++j) {
            one_sum.at(i).at(j) = one_sum.at(i - 1).at(j);
	        if (matrix.at(i - 1).at(j) == '1') {
             ++one_sum.at(i).at(j);
            }
          }
        }
        int max_sq = 0;
        for (int i = 1; i <= row; ++i) {
          for (int j = i; j <= row; ++j) {
            int sum_one_sq = 0;
	        for (int k = 0; k < col; ++k) {
	          if (one_sum.at(j).at(k) - one_sum.at(i - 1).at(k) == j - i + 1) {
	           sum_one_sq += j - i + 1;
              } else {
                sum_one_sq = 0;
              }
              if (sum_one_sq == (j - i + 1) * (j - i + 1)) {
                max_sq = max(max_sq, sum_one_sq);
              }
            }
          }
        }
        return max_sq;
    }
};
*/
