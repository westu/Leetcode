class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(const string& s) {
        if (s.empty() == true) {
            return 0;
        }
        int l = static_cast<int>(s.size());
        int prev_one, prev_two(1);
        prev_one = s.at(0) > '0' ? 1 : 0;
        for (int i = 1; i < l; ++i) {
            if (s.at(i) == '0') {
                if (s.at(i- 1) != '1' && s.at(i - 1) != '2') {
                    return 0;
                } else {
                    prev_one = prev_two;
                    continue;
                }
            }
            int tmp(prev_one);
            if (s.at(i - 1) == '1' && s.at(i) > '0' ||
                s.at(i - 1) == '2' && s.at(i) > '0' && s.at(i) <= '6') {
                tmp += prev_two;
            }
            prev_two = prev_one;
            prev_one = tmp;
        }
        return prev_one;
    }
};
