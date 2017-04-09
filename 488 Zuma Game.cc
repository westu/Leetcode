class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> hash_map;
        hash_map.insert(make_pair('R', 2));
        hash_map.insert(make_pair('Y', 3));
        hash_map.insert(make_pair('B', 5));
        hash_map.insert(make_pair('G', 7));
        hash_map.insert(make_pair('W', 11));
        
        int hand_num = 1;
        for (char c : hand) {
            hand_num *= hash_map.find(c)->second;
        }
        
        int min_step = -1;
        dfs(board, hand_num, hash_map, min_step, 0);
        return min_step;
    }

private:
    void dfs(string &board, int hand_num, const unordered_map<char, int> hash_map, int &min_step, int step) {
        int con_len;  // consecutive substr length
        do {
            con_len = 2;
            int len = static_cast<int>(board.size());
            for (int i = 0; i < len - 2; ++i) {
                for (; i + con_len - 1 < len && board[i + con_len - 1] == board[i]; ++con_len);
                --con_len;
                if (con_len > 2) {
                    board.erase(i, con_len);
                    break;
                }
            }
        } while (con_len > 2);
        
        
        if (board.empty()) {
            min_step = min_step == -1 ? step : min(step, min_step);
            return;
        }
        if (hand_num == 1) {  // used up
            return;
        }
        int len = static_cast<int>(board.size());
        for (int i = 0; i < len; ++i) {
            if ((i == 0 || i > 0 && board[i] != board[i - 1])
                && (hand_num % hash_map.find(board[i])->second == 0)) {
                if (i + 1 < board.size() && board[i] == board[i + 1]) {
                    string current_board = board.substr(0, i) + board.substr(i + 2, len - (i + 2));
                    dfs(current_board,
                        hand_num / hash_map.find(board[i])->second,
                        hash_map,
                        min_step,
                        step + 1);
                } else {
                    string current_board = board.substr(0, i) + board.substr(i, 1) + board.substr(i, len -i);
                    dfs(current_board,
                        hand_num / hash_map.find(board[i])->second,
                        hash_map,
                        min_step,
                        step + 1);
                }
            }
        }
    }
};
