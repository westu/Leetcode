class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if (numRows == 1) {
            return s;
        }
        for (int i = 0; i < numRows; i++) {
            for (int k = 0; ; k++) {
                int p1 = (2 * numRows - 2) * k - i % numRows;
                int p2 = (2 * numRows - 2) * k + i % numRows;
                if (p1 >= static_cast<int>(s.size())) {
                    break;
                }
                if (p1 >= 0 && i != (numRows - 1)) {
                    ans += s[p1];
                }
                if (p2 > p1 && p2 < static_cast<int>(s.size())) {
                    ans += s[p2];
                }
            }
        }
        return ans;   
    }
};
