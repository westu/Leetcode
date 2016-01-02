class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; ++i) {
            string tmp = "";
            int num = 0;
            for (int j = 0; j < static_cast<int>(ans.size()); ++j) {
                if (j == 0 || ans[j] == ans[j - 1]) {
                    ++num;
                } else {
                    tmp.push_back(num + '0');
                    tmp.push_back(ans[j - 1]);
                    num = 1;
                }
            }
            tmp.push_back(num + '0');
            tmp.push_back(ans[ans.size() - 1]);
            ans = tmp;
        }
        return ans;
    }
};
