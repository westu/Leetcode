class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() == true || matrix[0].empty() == true) {
            return;
        }
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        bool has_zero_first_row(false), has_zero_first_column(false);
        for (int i = 0; i < m; ++i) {
            if (matrix[0][i] == 0) {
                has_zero_first_row = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[i][0] == 0) {
                has_zero_first_column = true;
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (has_zero_first_row == true) {
            for (int i = 0; i < m; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (has_zero_first_column == true) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
