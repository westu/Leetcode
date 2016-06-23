class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int ans = 10;
        for (int i = 2; i <= n; ++i) {
            int count = 1;
            for (int j = 1; j <= i; ++j) {
                if (j == 1) {
                    count *= 9;
                } else {
                    count *= 9 - j + 2;
                }
            }
            ans += count;
        }
        return ans;
    }
};
