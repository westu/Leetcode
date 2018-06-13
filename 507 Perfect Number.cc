class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int left_num = num;
        int small_factor = 1;
        int big_factor = num;
        left_num -= small_factor;
        for (int i = small_factor + 1; i < big_factor;) {  // i <= sqrt(num) is also ok
            if (num % i == 0) {
                small_factor = i;
                big_factor = num / i;
                left_num -= small_factor;
                if (small_factor != big_factor) {
                    left_num -= big_factor;
                }
                i = small_factor + 1;
            } else {
                ++i;
            }
        }
        return left_num == 0;
    }
};
