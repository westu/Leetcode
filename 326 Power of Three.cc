class Solution {
public:
    bool isPowerOfThree(int n) {
        int m = log10(n) / log10(3);
        return n > 0 && (int)round(pow(3, m)) == n;
    }
};
