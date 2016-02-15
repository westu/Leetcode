class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() == true || matrix[0].empty() == true) {
            return ans;
        }
        int height = static_cast<int>(matrix.size());
        int width = static_cast<int>(matrix[0].size());
        for (int i = 0; i < (min(height, width) + 1) / 2; ++i) {
            if (height - (i + 1) == i) {  // there is a single row
                for (int j = i; j <= width - (i + 1); ++j) {
                    ans.push_back(matrix[i][j]);
                }
                continue;
            }
            if (width - (i + 1) == i) {  // there is a single column
                for (int j = i; j <= height - (i + 1); ++j) {
                    ans.push_back(matrix[j][i]);
                }
                continue;
            }
            // from (i, i) to (i, width - (i + 1))
            for (int j = i; j < width - (i + 1); ++j) {
                ans.push_back(matrix[i][j]);
            }
            // from (i, width - (i + 1)) to (height - (i + 1), width - (i + 1))
            for (int j = i; j < height - (i + 1); ++j) {
                ans.push_back(matrix[j][width - (i + 1)]);
            }
            // from (height - (i + 1), width - (i + 1)) to (height - (i + 1), i + 1)
            for (int j = width - (i + 1); j > i; --j) {
                ans.push_back(matrix[height - (i + 1)][j]);
            }
            // from (height - (i + 1), i + 1) to (i, i)
            for (int j = height - (i + 1); j > i; --j) {
                ans.push_back(matrix[j][i]);
            }
        }
        return ans;
    }
};
