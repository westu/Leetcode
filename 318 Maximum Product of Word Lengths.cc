class Solution {
public:
    int maxProduct(vector<string>& words) {
        int l = static_cast<int>(words.size());
        vector<int> words2chars(l, 0);
        for (int i = 0; i < l; ++i) {
            for (char c : words.at(i)) {
                words2chars.at(i) |= 1 << (c - 'a' + 1);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = i + 1; j < l; ++j) {
                if ((words2chars.at(i) & words2chars.at(j)) <= 1) {
                    ans = max(ans, static_cast<int>(words.at(i).size()) * static_cast<int>(words.at(j).size()));
                }
            }
        }
        return ans;
    }
};
