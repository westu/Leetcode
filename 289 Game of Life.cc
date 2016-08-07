class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return;
        }
        int n = static_cast<int>(board.size());
        int m = static_cast<int>(board.at(0).size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board.at(i).at(j) = next_generation(board, i, j) * 10 + board.at(i).at(j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board.at(i).at(j) = board.at(i).at(j) / 10;
            }
        }
    }

private:
    int next_generation(const vector<vector<int> > &board, int x, int y) {
        int live_num(0), dead_num(0);
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if ((i != 0 || j != 0) && (is_valid(board, x + i, y + j))) {
                    if (board.at(x + i).at(y + j) % 10 == 0) {
                        ++dead_num;
                    } else {
                        ++live_num;
                    }
                }
            }
        }
        
        if (board.at(x).at(y) == 1 && live_num < 2) {
            return 0;
        } else if (board.at(x).at(y) == 1 && (live_num == 2 || live_num == 3)) {
            return 1;
        } else if (board.at(x).at(y) == 1 && live_num > 3) {
            return 0;
        } else if (board.at(x).at(y) == 0 && live_num == 3) {
            return 1;
        } else {
            return board.at(x).at(y);
        }
    }

    bool is_valid(const vector<vector<int> > &board, int x, int y) {
        int n = static_cast<int>(board.size());
        int m = static_cast<int>(board.at(0).size());
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        } else {
            return true;
        }
    }
};
