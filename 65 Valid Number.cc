class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string s) {
        int l = static_cast<int>(s.length());
        int start(0), end(l);
        while (start < l && s.at(start) == ' ') {
            ++start;
        }
        while (end > 0 && s.at(end - 1) == ' ') {
            --end;
        }
        s = s.substr(start, end - start);
        if (s.empty() == true) {
            return false;
        }
        l = static_cast<int>(s.length());
        int e_count(0), point_count(0);
        int e_pos, point_pos;
        for (int i = 0; i < l; ++i) {
            if (s.at(i) == '-' || s.at(i) == '+') {
                if (i > 0 && s.at(i - 1) != 'e') {
                    return false;
                }
                if (i == l - 1 || is_digit(s.at(i + 1)) == false && s.at(i + 1) != '.') {
                    return false;
                }
            } else if (s.at(i) == 'e') {
                ++e_count;
                e_pos = i;
                if (e_count > 1) {
                    return false;
                }
            } else if (s.at(i) == '.') {
                ++point_count;
                point_pos = i;
                if (point_count > 1) {
                    return false;
                } else if (e_count == 1) {  // '.' must appear before 'e'
                    return false;
                }
            } else if (is_digit(s.at(i)) == false) {
                return false;
            }
        }
        if (point_count > 0 && (left_is_digit(s, point_pos) == false
                && right_is_digit(s, point_pos) == false)) {
            return false;
        }
        if (e_count > 0) {
            return isNumber(s.substr(0, e_pos)) && isNumber(s.substr(e_pos + 1, l - e_pos));
        } else {
            return true;
        }
    }

private:
    bool is_digit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    bool left_is_digit(const string& s, int pos) {
        int l = static_cast<int>(s.length());
        if (pos == 0 || is_digit(s.at(pos - 1)) == false) {
            return false;
        } else {
            return true;
        }
    }
    bool right_is_digit(const string& s, int pos) {
        int l = static_cast<int>(s.length());
        if (pos == l - 1 || is_digit(s.at(pos + 1)) == false) {
            return false;
        } else {
            return true;
        }
    }
};
