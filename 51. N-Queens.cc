class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, true), lch(2 * n, true), rch(2 * n, true);
        dfs(0, board, col, lch, rch, ans, n);
        return ans;
    }

private:
    void dfs(int x, vector<string>& board, vector<bool>& col, vector<bool>& lch,
             vector<bool>& rch, vector<vector<string> >& ans, int n) {
        if (x == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col[i] == true && lch[n - 1 - (x - i)] == true &&
                rch[i + x] == true) {
                col[i] = false;
                lch[n - 1 - (x - i)] = false;
                rch[i + x] = false;
                board[x][i] = 'Q';
                dfs(x + 1, board, col, lch, rch, ans, n);
                col[i] = true;
                lch[n - 1 - (x - i)] = true;
                rch[i + x] = true;
                board[x][i] = '.';
            }
        }
    }
};
