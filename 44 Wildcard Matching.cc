class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) {
        if (s == "") {
            return p == "" || p == "*";
        }
        if (p == "") {
            return s == "";
        }
        int letter_num = 0;
        for (int i = 0; i < static_cast<int>(p.size()); ++i) {
            if (p[i] != '*') {
                ++letter_num;
            }
        }
        int l1 = static_cast<int>(s.size());
        int l2 = static_cast<int>(p.size());
        if (letter_num > l1) {
            return false;
        }
        vector<vector<bool> > dp(2, vector<bool>(l2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= l2; ++i) {
            dp[0][i] = p[i - 1] == '*' ? dp[0][i - 1] : false;
        }
        int now_i = 1;
        for (int i = 1; i <= l1; ++i) {
            dp[now_i][0] = false;
            for (int j = 1; j <= l2; ++j) {
                dp[now_i][j] = false;
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[now_i][j] = dp[now_i ^ 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[now_i][j] = dp[now_i ^ 1][j] || dp[now_i][j - 1];
                }
            }
            now_i = now_i ^ 1;
        }
        return dp[now_i ^ 1][l2];
    }
};
