class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        if (t.empty()) {
            return false;
        }
        int slen = static_cast<int>(s.size());
        int tlen = static_cast<int>(t.size());
        for (int i = 0, j = 0; i < tlen; ++i) {
            if (t.at(i) == s.at(j)) {
                ++j;
            }
            if (j == slen) {
                return true;
            }
        }
        return false;
    }
};
