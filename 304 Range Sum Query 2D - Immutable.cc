class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix.at(0).empty()) {
            return;
        }
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        sum = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
        cal_sub_sum(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum.at(row2 + 1).at(col2 + 1) - sum.at(row1).at(col2 + 1) - sum.at(row2 + 1).at(col1)
            + sum.at(row1).at(col1);
    }

private:
    vector<vector<int> > sum;

    void cal_sub_sum(const vector<vector<int>> &matrix) {
        vector<vector<int> > tmp_sum(matrix);
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tmp_sum.at(i).at(j) += tmp_sum.at(i - 1).at(j);
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum.at(i).at(j) = sum.at(i).at(j - 1) + tmp_sum.at(i - 1).at(j - 1);
            }
        }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
