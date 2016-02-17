class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() == true || obstacleGrid[0].empty() == true
            || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m, n;
        m = static_cast<int>(obstacleGrid.size());
        n = static_cast<int>(obstacleGrid[0].size());
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            if (i > 0) {  // go down
                for (int j = 0; j < n; ++j) {
                    if (obstacleGrid[i - 1][j] == 1) {
                        dp[j] = 0;
                    }
                }
            }
            for (int j = 1; j < n; ++j) {  // go right
                if (obstacleGrid[i][j - 1] == 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
