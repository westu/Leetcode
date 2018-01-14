class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.empty()) {
            return S;
        }
        string ans;
        int len = static_cast<int>(S.size());
        for (int i = len - 1; i >= 0; --i) {
            if (S.at(i) != '-') {
                if (static_cast<int>(ans.size()) % (K + 1) == K) {
                    ans.push_back('-');
                }
                ans.push_back(toupper(S.at(i)));
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
