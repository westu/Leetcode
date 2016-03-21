class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int l = static_cast<int>(ans.size());
            for (int j = l - 1; j >= 0; --j) {
                ans.push_back(ans.at(j) + (1 << (i - 1)));
            }
        }
        return ans;
    }
};
