class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        int f1(1), f2(2);
        if (n <= 1) {
            return f1;
        } else if (n == 2) {
            return f2;
        } else {
            int f3;
            for (int i = 3; i <= n; ++i) {
                f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
            }
            return f3;
        }
    }
};
