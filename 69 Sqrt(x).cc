class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        long long y = static_cast<long long>(x);
        long long s(0), t(y + 1);
        while (s < t) {
            long long mid = s + (t - s) / 2;
            if (sq(mid) <= x && sq(mid + 1) > x) {
                return static_cast<int>(mid);
            }
            if (sq(mid) > x) {
                t = mid;
            } else {
                s = mid + 1;
            }
        }
        return static_cast<int>(s);
    }

private:
    long long sq(long long x) {
        return x * x;
    }
};
