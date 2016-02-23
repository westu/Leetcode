class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        if (a.empty() == true) {
            return b;
        }
        if (b.empty() == true) {
            return a;
        }
        if (a.length() < b.length()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        int l1 = static_cast<int>(a.length());
        int l2 = static_cast<int>(b.length());
        int w = 0;
        for (int i(l1 - 1), j(l2 - 1); j >= 0; --i, --j) {
            int tmp = a.at(i) - '0' + b.at(j) - '0' + w;
            a.at(i) = tmp % 2 + '0';
            w = tmp / 2;
        }
        for (int i = l1 - 1 - l2; i >= 0; --i) {
            if (w == 0) {
                break;
            }
            int tmp = a.at(i) - '0' + w;
            a.at(i) = tmp % 2 + '0';
            w = tmp / 2;
        }
        if (w > 0) {
            a = '1' + a;
        }
        return a;
    }
};
