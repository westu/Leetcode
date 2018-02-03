class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        long long max_half = pow(10, n) - 1, min_half = pow(10, n - 1) - 1;
        for (long long i = max_half; i > min_half; --i) {
            long long palindrome_num = get_palindrome(i);
            if (palindrome_num > max_half * max_half) {
                continue;
            }
            
            for (long long j = max_half; j > min_half; --j) {
                if (palindrome_num % j == 0) {
                    return palindrome_num % 1337;
                }
                if (j * j < palindrome_num) {
                    break;
                }
            }
        }
    }
private:
    long long get_palindrome(long long left_half) {
        long long palindrome_num = left_half;
        while (left_half > 0) {
            palindrome_num = palindrome_num * 10 + left_half % 10;
            left_half /= 10;
        }
        return palindrome_num;
    }
};
