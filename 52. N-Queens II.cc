class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> col(n, true), lch(2 * n, true), rch(2 * n, true);
        dfs(0, col, lch, rch, ans, n);
        return ans;
    }

private:
    void dfs(int x, vector<bool>& col, vector<bool>& lch,
             vector<bool>& rch, int& ans, int n) {
        if (x == n) {
            ++ans;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col[i] == true && lch[n - 1 - (x - i)] == true &&
                rch[i + x] == true) {
                col[i] = false;
                lch[n - 1 - (x - i)] = false;
                rch[i + x] = false;
                dfs(x + 1, col, lch, rch, ans, n);
                col[i] = true;
                lch[n - 1 - (x - i)] = true;
                rch[i + x] = true;
            }
        }
    }
};
