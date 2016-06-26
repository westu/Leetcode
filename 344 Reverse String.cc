class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) {
            return s;
        }
        int l = static_cast<int>(s.size());
        for (int i = 0; i < l / 2; ++i) {
            char c = s.at(i);
            s.at(i) = s.at(l - 1 - i);
            s.at(l - 1 - i) = c;
        }
        return s;
    }
};
