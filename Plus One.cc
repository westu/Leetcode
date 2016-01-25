class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = static_cast<int>(digits.size());
        if (len == 0) {
            return vector<int>(1, 1);
        }
        vector<int> ans;
        int w = 1;
        for (int i = len - 1; i >= 0; --i) {
            int tmp = digits[i] + w;
            ans.push_back(tmp % 10);
            w = tmp / 10;
        }
        if (w > 0) {
            ans.push_back(w);
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};
