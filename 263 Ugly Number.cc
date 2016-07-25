class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        vector<int> prime_fac(3);
        prime_fac.at(0) = 2;
        prime_fac.at(1) = 3;
        prime_fac.at(2) = 5;
        for (int p : prime_fac) {
            while (num != 0 && num % p == 0) {
                num /= p;
            }
        }
        return num == 1;
    }
};
