class Solution {
private:
    bool next_char_is_star(string s, int p) {
        if (p + 1 == static_cast<int>(s.size())) {  // s[p] is the last
            return false;
        }
        return s[p + 1] == '*';
    }
    bool dfs(string s, int p1, string t, int p2) {
        int len1, len2;
        len1 = static_cast<int>(s.size());
        len2 = static_cast<int>(t.size());
        if (p1 == len1 && p2 == len2) {
            return true;
        }
        if (next_char_is_star(t, p2) == false) {
            if (p1 < len1 && p2 < len2 && (s[p1] == t[p2] || t[p2] == '.')) {
                if (dfs(s, p1 + 1, t, p2 + 1) == true) {
                    return true;
                }
            }
        } else {
            if (dfs(s, p1, t, p2 + 2) == true) {  // regard '*' as 0
                return true;
            }
            if (p1 < len1 && (s[p1] == t[p2] || t[p2] == '.')) {
                if (dfs(s, p1 + 1, t, p2) == true) {
                    return true;
                }
            }
        }
        /*
        if (p1 < len1 && p2 < len2 && t[p2] != '.'
            && next_char_is_star(t, p2) == false) {
            if (s[p1] != t[p2]) {
                return false;
            } else if (dfs(s, p1 + 1, t, p2 + 1) == true) {
                return true;
            }
        } else if (p1 < len1 && p2 < len2 && t[p2] == '.') {
            if (dfs(s, p1 + 1, t, p2 + 1) == true) {
                return true;
            }
        } else if (next_char_is_star(t, p2) == true) {
            if (dfs(s, p1, t, p2 + 2) == true) {  // regard '*' as 0
                return true;
            }
            if (p1 < len1 && s[p1] == t[p2]) {
                if (dfs(s, p1 + 1, t, p2) == true) {
                    return true;
                }
            }
        }*/
        return false;
    }

public:
    bool isMatch(string s, string p) {
        return dfs(s, 0, p, 0);
    }
};
