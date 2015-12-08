class Solution {
private:
    bool is_not_num(char ch) {
        if (ch >='0' && ch <= '9') {
            return false;
        } else {
            return true;
        }
    }
  
public:
    int myAtoi(string str) {
        int start_pos = 0;
        while (start_pos < static_cast<int>(str.length()) && str[start_pos] == ' ') {
            start_pos++;
        }
        str = str.substr(start_pos, str.length());
        if (str == "") {
            return 0;
        }
        int symbol = 1;
        if (str[0] == '-') {
            symbol = -1;
            str = str.substr(1, str.length());
        } else if (str[0] == '+') {
            str = str.substr(1, str.length());
        }
        if (static_cast<int>(str.length()) > 0 && is_not_num(str[0])) {
            return 0;
        }
        int ans, prev_ans;
        ans = prev_ans = 0;
        for (int i = 0; i < static_cast<int>(str.length()); i++) {
            if (is_not_num(str[i]) == true) {
                break;
            }
            ans = ans * 10 + str[i] - '0';
            if (ans / 10 != prev_ans) {  // over flow checking
                long long return_ans = (long long)1 << 31;
                // Positive INT_MAX_VALUE = 1 << 31 - 1, negative INT_ MIN_VALUE = -(1 << 31)
                if (symbol == 1) {
                    return_ans -= 1;
                }
                return static_cast<int>(return_ans * symbol);
            }
            prev_ans = ans;
        }
        return symbol * ans;
    }
};
