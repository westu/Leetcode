class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        int l = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        long long bits = (1 << l) - 1;
        vector<vector<int> > ans;
        vector<int> tmp;
        ans.push_back(tmp);  // []
        for (long long i = 1; i <= bits; ++i) {
            vector<int> tmp_ans;
            int w = 0;
            long long tmp_i = i;
            while (tmp_i > 0) {
                if (tmp_i & 1 == 1) {
                    tmp_ans.push_back(nums.at(w));
                }
                tmp_i >>= 1;
                ++w;
            }
            ans.push_back(tmp_ans);
        }
        return ans;
    }
};
