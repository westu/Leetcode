class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }
        int i(0), l(static_cast<int>(nums.size()));
        for (int j = 0; j < l; ++j) {
            if (nums.at(j) - nums.at(i) != j - i) {
                string s = to_string(nums.at(i));
                if (j > i + 1) {
                    s += "->" + to_string(nums.at(j - 1));
                }
                ans.push_back(s);
                i = j;
            }
        }
        
        string s = to_string(nums.at(i));
        if (i < l - 1) {
            s += "->" + to_string(nums.back());
        }
        ans.push_back(s);
        
        return ans;
    }
};
