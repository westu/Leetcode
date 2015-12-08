class Solution {
public:
    int reverse(int x) {
        int symbol = x < 0 ? -1 : 1;
        x = abs(x);
        long long ans = 0;
        while (x > 0) {
            ans = ans * 10 + x %10;
            x /= 10;
        }
        if (abs(ans) >= ((long long)1 << 31)) {
            return 0;
        }
        return ans * symbol;
    }
};
