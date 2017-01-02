class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty() || g.empty()) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans =0;
        for (int i = 0, j = 0; i < static_cast<int>(g.size()) && j < static_cast<int>(s.size());) {
            if (g.at(i) <= s.at(j)) {
                ++ans;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
