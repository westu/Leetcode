class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() == true || board[0].empty() == true) {
            return false;
        }
        int n = static_cast<int>(board.size());
        int m = static_cast<int>(board[0].size());
        vector<vector<bool> > status(n, vector<bool>(m, true));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board.at(i).at(j) == word.at(0)) {
                    status.at(i).at(j) = false;
                    if (dfs(board, i, j, word, 1, status) == true) {
                        return true;
                    }
                    status.at(i).at(j) = true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(const vector<vector<char> > &board, int x, int y, const string &word,
             int w, vector<vector<bool> > &status) {
        if (w == static_cast<int>(word.size())) {
            return true;
        }
        int n = static_cast<int>(board.size());
        int m = static_cast<int>(board[0].size());
        if (x > 0 && board.at(x - 1).at(y) == word.at(w)
            && status.at(x - 1).at(y) == true) {
            status.at(x - 1).at(y) = false;
            if (dfs(board, x - 1, y, word, w + 1, status) == true) {
                return true;
            }
            status.at(x - 1).at(y) = true;
        }
        if (x < n - 1 && board.at(x + 1).at(y) == word.at(w)
            && status.at(x + 1).at(y) == true) {
            status.at(x + 1).at(y) = false;
            if (dfs(board, x + 1, y, word, w + 1, status) == true) {
                return true;
            }
            status.at(x + 1).at(y) = true;
        }
        if (y > 0 && board.at(x).at(y - 1) == word.at(w)
            && status.at(x).at(y - 1) == true) {
            status.at(x).at(y - 1) = false;
            if (dfs(board, x, y - 1, word, w + 1, status) == true) {
                return true;
            }
            status.at(x).at(y - 1) = true;
        }
        if (y < m - 1 && board.at(x).at(y + 1) == word.at(w)
            && status.at(x).at(y + 1) == true) {
            status.at(x).at(y + 1) = false;
            if (dfs(board, x, y + 1, word, w + 1, status) == true) {
                return true;
            }
            status.at(x).at(y + 1) = true;
        }
        return false;
    }
};
