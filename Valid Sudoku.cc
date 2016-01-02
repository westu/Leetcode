class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if (static_cast<int>(board.size() != 9)) {
            return false;
        }
        // check for single row
        for (int i = 0; i < 9; ++i) {
            if (static_cast<int>(board[i].size()) != 9) {
                return false;
            }
            vector<bool> check_table(9, true);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (check_table[board[i][j] - '0'] == false) {
                        return false;
                    }
                    check_table[board[i][j] - '0'] = false;
                }
            }
        }
        // check for single column
        for (int i = 0; i < 9; ++i) {
            vector<bool> check_table(9, true);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (check_table[board[j][i] - '0'] == false) {
                        return false;
                    }
                    check_table[board[j][i] - '0'] = false;
                }
            }
        }
        // check for single board
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> check_table(9, true);
                for (int k = 0; k < 3; ++k) {  
                    for (int l = 0; l < 3; ++l) {
                        if (board[i + k][j + l] != '.') {
                            int num = board[i + k][j + l] - '0';
                            if (check_table[num] == false) {
                                return false;
                            }
                            check_table[num] = false;
                        }
                    }
                }
                // for (int k = 0; k < 9; ++k)
                // check(board[i + k /3][j + k % 3]
                // this method is better
            }
        }
        return true;
    }
};
