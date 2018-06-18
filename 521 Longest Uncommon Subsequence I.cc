class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.compare(b) == 0) {
            return -1;
        } else {
            return max(static_cast<int>(a.size()), static_cast<int>(b.size()));
        }
    }
};
