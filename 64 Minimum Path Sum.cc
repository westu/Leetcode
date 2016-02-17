class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() == true || grid[0].empty() == true) {
            return 0;
        }
        int m, n;
        m = static_cast<int>(grid.size());
        n = static_cast<int>(grid[0].size());
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                if (i == 0) {
                    dp[j] = dp[j- 1] + grid[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};
