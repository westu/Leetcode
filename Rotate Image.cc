class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty() == true || matrix[0].empty() == true) {
            return;
        }
        int l = static_cast<int>(matrix.size());
        for (int i = 0; i <= (l - 1) / 2; ++i) {
            for (int j = 0; j < l / 2; ++j) {
                int tmp = matrix[l - 1 - j][i];
                matrix[l - 1 - j][i] = matrix[l - 1 - i][l - 1 - j];
                matrix[l - 1 - i][l - 1 - j]= matrix[j][l - 1 - i];
                matrix[j][l - 1 - i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};
