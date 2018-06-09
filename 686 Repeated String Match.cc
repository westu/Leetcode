class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (A.empty()) {
            return B.empty() ? 0 : -1;
        }
        int alen = static_cast<int>(A.size());
        int blen = static_cast<int>(B.size());
        
        string C;
        for (int i = 0; i < blen / alen + 2; ++i) {
            C += A;
        }
        
        for (int i = 0; i < alen; ++i) {
            if (C.substr(i, blen) == B) {
                // C'substr [i, i + blen - 1]
                return (i + blen) % alen == 0 ? (i + blen) / alen : (i + blen) / alen + 1;
            }
        }
        
        return -1;
    }
};
