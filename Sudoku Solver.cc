class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > r(9, vector<bool>(9, true));  // row
        vector<vector<bool> > c(9, vector<bool>(9, true));  // column
        vector<vector<bool> > b(9, vector<bool>(9, true));  // block
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    r[i][num] = false;
                    c[j][num] = false;
                    b[i / 3 * 3 + j / 3][num] = false;
                }
            }
        }
        dfs(board, r, c, b, 0, 0);
    }

private:
    bool dfs(vector<vector<char> >& board, vector<vector<bool> >& r,
             vector<vector<bool> >& c, vector<vector<bool> >& b,
             int x, int y) {
        if (y == 9) {
            x = x + 1;
            y = 0;
        }
        if (x == 9) {
            return true;
        }
        if (board[x][y] != '.') {
            return dfs(board, r, c, b, x, y + 1);
        } else {
            for (int i = 0; i < 9; ++i) {
                if (r[x][i] == true && c[y][i] == true &&
                    b[x / 3 * 3 + y / 3][i] == true) {
                    r[x][i] = false;
                    c[y][i] = false;
                    b[x / 3 * 3 + y / 3][i] = false;
                    board[x][y] = i + 1 + '0';
                    if (dfs(board, r, c, b, x, y + 1) == true) {
                        return true;
                    }
                    r[x][i] = true;
                    c[y][i] = true;
                    b[x / 3 * 3 + y / 3][i] = true;
                    board[x][y] = '.';
                }
            }
            return false;
        }
    }
};
