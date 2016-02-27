class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() == true || matrix[0].empty() == true) {
            return false;
        }
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        int x(0), y(m - 1);
        while (x < n && y >= 0) {
            if (matrix.at(x).at(y) == target) {
                return true;
            } else if (matrix.at(x).at(y) < target) {
                ++x;
            } else {
                --y;
            }
        }
        return false;
    }
};
