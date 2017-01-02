class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.empty() || str.size() == 1) {
            return false;
        }
        int len = static_cast<int>(str.size());
        for (int i = 1; i <= len / 2; ++i) {
            if (len % i == 0 && check(str, i)) {
                return true;
            }
        }
        return false;
    }

private:
    bool check(const string &str, int sub_len) {
        int len = static_cast<int>(str.size());
        for (int i = 0; i < sub_len; ++i) {
            for (int j = i; j < len; j += sub_len) {
                if (str.at(j) != str.at(i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
