class Solution {
private:
    bool palindromic(string s, int start, int len) {
        for (int i = 0; i < len / 2; i++) {
            if (s[start + i] != s[start + len - i - 1]) {
                return false;
            }
        }

        return true;
    }

public:
    string longestPalindrome(string s) {
        string ans = "";

        if (s.length() > 0) {
            ans.push_back(s[0]);
        }

        int max_len = 0;
        int start_pos, end_pos;

        // substring's length is odd
        for (int i = 1; i < s.length() - 1; i++) {
            int l = min(i, static_cast<int>(s.length()) - (i + 1));
            for (int j = 1; j <= l; j++) {
                if (s[i - j] == s[i + j]) {
                    if (2 * j + 1 > max_len) {
                        max_len = 2 * j + 1;
                        start_pos = i - j;
                        // end_pos = i + j;
                    }
                } else {
                    break;
                }
            }
        }

        // substring's length is even
        for (int i = 0; i < s.length() - 1; i++) {
            int l  = min(i + 1, static_cast<int>(s.length()) - (i + 1));
            for (int j = 1; j <= l; j++) {
                if (s[i - j + 1] == s[i + j]) {
                    if (2 * j > max_len) {
                        max_len = 2 * j;
                        start_pos = i - j + 1;
                        // end_pos = i + j;
                    }
                } else {
                    break;
                }
            }
        }

        if (max_len > 0) {
            ans = s.substr(start_pos, max_len);
        }
        return ans;

        /*
        // string tmp;
        for (int l = s.length(); l >= 1; l--) {
            //l : length of substring
            // tmp = "";
            for (int i = 0; (i + l - 1) < s.length(); i++) {
                // tmp.push_back(s[i + l -1]);
                // tmp = s.substr(i, l);
                if (palindromic(s, i, l) == true) {
                    return s.substr(i, l);
                }
            }
        }*/
    }
};
