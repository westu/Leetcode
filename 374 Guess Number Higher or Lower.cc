// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int add_value = 1;
        int delete_value = 1;
        while (true) {
            if (guess(n) == 0) {
                return n;
            } else if (guess(n) == 1) {
                n = n + add_value;
                add_value *= 2;
                delete_value = 1;
            } else {
                n = n - delete_value;
                delete_value *= 2;
                add_value = 1;
            }
        }
    }
};
