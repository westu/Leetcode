class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
                long long max_int;
        int symbol;
        if (static_cast<long long>(dividend) * divisor < 0) {
            symbol = -1;
            max_int = 1LL << 31;
        } else {
            symbol = 1;
            max_int = (1LL << 31) - 1;
        }
        if (divisor == 0) {
            if (dividend >= 0) {
                return static_cast<int>(max_int);
            } else {
                return -1 * static_cast<int>(max_int) - 1;
            }
        }
        long long d, r, ans;
        d = abs(static_cast<long long>(dividend));
        r = abs(static_cast<long long>(divisor));
        ans = 0;
        while (d >= r) {
            int w;
            for (w = 0; (r << (w + 1)) <= d; w++);
            ans += (1LL << w);
            d -= (r << w);
        }
        ans = min(ans, max_int);
        return static_cast<int>(symbol * ans);
    }
};
