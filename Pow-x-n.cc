class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        double ans(1);
        bool posi = n >= 0 ? true : false;
        n = abs(n);
        while (n > 0) {
            if (n & 1 > 0) {
                ans *= x;
            }
            n = n >> 1;
            x *= x;
        }
        ans = posi == true ? ans : 1.0 / ans;
        return ans;
    }
};
