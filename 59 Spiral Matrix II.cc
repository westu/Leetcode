class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));
        int num = 1;
        for (int i = 0; i <= (n - 1) / 2; ++i) {
            int l = n - 2 * i;
            if (l == 1) {
                ans[i][i] = num++;
                continue;
            }
            int x = i;
            int y = i;
            for (int j = 1; j < l; ++j) {
                ans[x][y++] = num++;
            }
            for (int j = 1; j < l; ++j) {
                ans[x++][y] = num++;
            }
            for (int j = 1; j < l; ++j) {
                ans[x][y--] = num++;
            }
            for (int j = 1; j < l; ++j) {
                ans[x--][y] = num++;
            }
        }
        return ans;
    }
};
