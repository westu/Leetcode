class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        }
        string str;
        while (x > 0) {
            str += '0' + (x % 10);
            x /= 10;
        }
        int len = static_cast<int>(str.length());
        for (int i = 0; i <= len / 2 - 1; i++) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
