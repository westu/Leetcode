class Solution {
public:
    bool isPerfectSquare(int num) {
        double a(num), n(num), m;
        while (true) {
            m = (n + a / n) / 2;
            if (fabs(m - n) < 0.00001) {
                break;
            }
            n = m;
        }
        return fabs(m - round(m)) < 0.00001;
    }
};
