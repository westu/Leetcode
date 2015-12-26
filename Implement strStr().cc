class Solution {
private:
    bool check_equal(string& s, int w, string& t) {
        for (int i = 0; i < static_cast<int>(t.size()); i++) {
            if (t[i] != s[w + i]) {
                return false;
            }
        }
        return true;
    }

public:
    int strStr(string haystack, string needle) {
        if (haystack == "" && needle == "") {
            return 0;
        } else if (haystack == "") {
            return -1;
        } else if (needle == "") {
            return 0;
        }
        for (int i = 0; i <= static_cast<int>(haystack.size()) - 
            static_cast<int>(needle.size()); i++) {
            if (check_equal(haystack, i, needle) == true) {
                return i;
            }
        }
        return -1;
    }
};
